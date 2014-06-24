<?php
/**
 * @file
 * prometheus_sample_content_and_dependencies.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function prometheus_sample_content_and_dependencies_filter_default_formats() {
  $formats = array();

  // Exported format: Advanced Full HTML.
  $formats['advanced_full_html'] = array(
    'format' => 'advanced_full_html',
    'name' => 'Advanced Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(),
  );

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'filter_html' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<em> <strong> <cite> <blockquote> <code> <ul> <ol> <li> <dl> <dt> <dd> <p> <a>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'htmLawed' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'htmLawed' => array(
            'config' => '\'safe\'=>0, \'tidy\'=>1, \'deny_attribute\'=>\'id, style\'',
            'spec' => '',
            'help' => 'The id and style attributes are removed from this text format.',
          ),
        ),
      ),
      'filter_autop' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -7,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
