<?php
/**
 * @file
 * prometheus_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function prometheus_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_blog:blog
  $menu_links['main-menu_blog:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'identifier' => 'main-menu_blog:blog',
      'attributes' => array(
        'class' => array(
          0 => 'blog-link',
        ),
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_contact:contact
  $menu_links['main-menu_contact:contact'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'contact',
    'router_path' => 'contact',
    'link_title' => 'Contact',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_contact:contact',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_view-sample-styles:node/89
  $menu_links['main-menu_view-sample-styles:node/89'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/89',
    'router_path' => 'node/%',
    'link_title' => 'View Sample Styles',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_view-sample-styles:node/89',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_blog:blog',
  );
  // Exported menu link: menu-categories_category-1:taxonomy/term/2
  $menu_links['menu-categories_category-1:taxonomy/term/2'] = array(
    'menu_name' => 'menu-categories',
    'link_path' => 'taxonomy/term/2',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Category 1',
    'options' => array(
      'attributes' => array(
        'title' => 'Category 1',
      ),
      'identifier' => 'menu-categories_category-1:taxonomy/term/2',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-categories_category-2:taxonomy/term/3
  $menu_links['menu-categories_category-2:taxonomy/term/3'] = array(
    'menu_name' => 'menu-categories',
    'link_path' => 'taxonomy/term/3',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Category 2',
    'options' => array(
      'attributes' => array(
        'title' => 'Category 2',
      ),
      'identifier' => 'menu-categories_category-2:taxonomy/term/3',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-categories_category-3:taxonomy/term/4
  $menu_links['menu-categories_category-3:taxonomy/term/4'] = array(
    'menu_name' => 'menu-categories',
    'link_path' => 'taxonomy/term/4',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Category 3',
    'options' => array(
      'attributes' => array(
        'title' => 'Category 3',
      ),
      'identifier' => 'menu-categories_category-3:taxonomy/term/4',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Exported menu link: menu-categories_category-4:taxonomy/term/5
  $menu_links['menu-categories_category-4:taxonomy/term/5'] = array(
    'menu_name' => 'menu-categories',
    'link_path' => 'taxonomy/term/5',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Category 4',
    'options' => array(
      'attributes' => array(
        'title' => 'Category 4',
      ),
      'identifier' => 'menu-categories_category-4:taxonomy/term/5',
    ),
    'module' => 'taxonomy_menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  t('Category 1');
  t('Category 2');
  t('Category 3');
  t('Category 4');
  t('Contact');
  t('Home');
  t('View Sample Styles');


  return $menu_links;
}
