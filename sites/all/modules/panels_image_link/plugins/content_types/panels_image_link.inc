<?php
/**
 * @file
 * Simple panels content type for displaying an uploaded image and linking it to a provided url/path
 */
/** @noinspection PhpUnusedLocalVariableInspection */
$plugin = array(
  'title'           => t('Image Link'),
  'content_types'   => 'panels_image_link',
  'single'          => FALSE,
  'render callback' => 'panels_image_link_render',
  'description'     => t('Displays an uploaded image and linking it to a provided url/path.'),
  'edit form'       => 'panels_image_link_edit_form',
  'admin title'     => 'panels_image_link_admin_title',
  'admin info'      => 'panels_image_link_admin_info',
  'category'        => array(
    'miscellaneous',
    0
  ),
  'all contexts'    => TRUE,
);
/**
 * Title callback for admin page
 */
function panels_image_link_admin_title($subtype, $conf, $context = NULL) {
  return t('Image Link');
}

/**
 * Callback to provide administrative info (the preview in panels when building a panel).
 */
function panels_image_link_admin_info($subtype, $conf, $context = NULL) {
  $block = new stdClass();
  $block->title = t('Image Link');
  $config = array();
  if ( $conf['override_title'] == TRUE ) {
    $title_value = '<b>' . $conf['override_title_text'] . '</b>';
  }
  else {
    $title_value = t('Not Set');
  }
  $config[] = t('Title') . ': ' . $title_value;
  $config[] = t('Target') . ': <b>' . ( isset( $conf['target_url'] ) && !empty( $conf['target_url'] ) ? htmlentities($conf['target_url']) : t('Not Set') ) . '</b>';
  $config[] = t('Caption') . ': ' . ( isset( $conf['caption'] ) && !empty( $conf['caption'] ) ? filter_xss_admin($conf['caption']) : t('Not Set') );
  $config[] = t('Filename') . ': <b>' . ( isset( $conf['image'] ) ? drupal_realpath('public://' . $conf['image']) : t('Not Set') ) . '</b>';
  $block->content = theme_item_list(array( 'items' => $config, 'title' => NULL, 'type' => 'ul', 'attributes' => array() ));
  return $block;
}

/**
 * Run-time rendering of the body of the block (content type)
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time
 * @param $args
 * @param $context
 *   Context - in this case we don't have any
 *
 * @return
 *   An object with at least title and content members
 */
function panels_image_link_render($subtype, $conf, $args, $context) {
  if ( isset( $conf['image'] ) ) {
    $caption = NULL;
    $url = NULL;
    if ( isset( $conf['caption'] ) && !empty( $conf['caption'] ) ) {
      $caption = $conf['caption'];
      // Update the strings to allow context substitution.
      if ( !empty( $context ) ) {
        $caption = ctools_context_keyword_substitute($conf['caption'], array(), $context);
      }
    }
    if ( isset( $conf['target_url'] ) && !empty( $conf['target_url'] ) ) {
      $url = $conf['target_url'];
      // Update the strings to allow context substitution.
      if ( !empty( $context ) ) {
        $url = ctools_context_keyword_substitute($conf['target_url'], array(), $context);
      }
    }
    $link_theme_array = array(
      '#theme'      => 'panels_image_link',
      '#path'       => file_create_url('public://' . $conf['image']),
      '#caption'    => $caption,
      '#target_url' => $url,
    );
    $block = new stdClass();
    if ( $conf['override_title'] == TRUE ) {
      $block->title = $conf['override_title_text'];
    }
    else {
      $block->title = NULL;
    }
    $block->content = render($link_theme_array);
    return $block;
  }
  return NULL;
}

/**
 * Edit callback for the content type.
 */
function panels_image_link_edit_form($form, &$form_state) {
  $display = & $form_state['display'];
  //Disable title override description markup (adds clutter, and isn't very useful in this module)
  unset( $form['override_title_markup'] );
  $conf = $form_state['conf'];
  $form['target_url'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Link Target'),
    '#description'   => t('Leave blank to prevent the image from being rendered as a link.  You may use substitutions in this field.'),
    '#default_value' => isset( $conf['target_url'] ) ? $conf['target_url'] : '',
  );
  $form['caption'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Caption'),
    '#description'   => t('Leave blank to prevent a caption from being rendered below the image.  You may use substitutions in this field.'),
    '#size'          => 100,
    '#default_value' => isset( $conf['caption'] ) ? $conf['caption'] : '',
  );
  $rows = array();
  foreach ( $display->context as $context ) {
    foreach ( ctools_context_get_converters('%' . check_plain($context->keyword) . ':', $context) as $keyword => $title ) {
      $rows[] = array(
        check_plain($keyword),
        t('@identifier: @title', array( '@title' => $title, '@identifier' => $context->identifier )),
      );
    }
  }
  $header = array( t('Keyword'), t('Value') );
  $form['contexts'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Substitutions'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
    '#value'       => theme('table', array( 'header' => $header, 'rows' => $rows )),
  );
  $form['image'] = array(
    '#type'          => 'file',
    '#title'         => t('Image'),
    '#description'   => isset( $conf['image'] ) ? t('Currently set as:') . ' ' . drupal_realpath('public://' . $conf['image']) : '',
    '#default_value' => isset( $conf['image'] ) ? $conf['image'] : '',
  );
  return $form;
}

/**
 * Validation callback for the content type.
 */
function panels_image_link_edit_form_validate($form, &$form_state) {
  $file_validators = array(
    'file_validate_is_image' => array(), // Validates file is really an image.
  );
  $file = file_save_upload('image', $file_validators);
  // If the file passed validation:
  if ( $file ) {
    // Move the file, into the Drupal file system
    if ( $file = file_move($file, 'public://') ) {
      // Save the file for use in the submit handler.
      $form_state['storage']['image'] = $file;
    }
    else {
      form_set_error('image', t('Failed to write the uploaded file the site\'s file folder.'));
    }
  }
}

/**
 * Submit callback for settings form
 */
function panels_image_link_edit_form_submit($form, &$form_state) {
  if ( isset( $form_state['storage']['image'] ) ) {
    $file = $form_state['storage']['image'];
    // We are done with the file, remove it from storage.
    unset( $form_state['storage']['image'] );
    // Make the storage of the file permanent
    $file->status = FILE_STATUS_PERMANENT;
    // Save file status.
    file_save($file);
    $form_state['values']['image'] = $file->filename;
  }
  foreach ( element_children($form) as $key ) {
    if ( isset( $form_state['values'][$key] ) ) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}