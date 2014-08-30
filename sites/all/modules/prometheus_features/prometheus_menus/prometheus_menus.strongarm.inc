<?php
/**
 * @file
 * prometheus_menus.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function prometheus_menus_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_1_admin_title';
  $strongarm->value = 'Main menu block';
  $export['menu_block_1_admin_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_1_depth';
  $strongarm->value = '2';
  $export['menu_block_1_depth'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_1_expanded';
  $strongarm->value = 0;
  $export['menu_block_1_expanded'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_1_follow';
  $strongarm->value = 0;
  $export['menu_block_1_follow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_1_level';
  $strongarm->value = '1';
  $export['menu_block_1_level'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_1_parent';
  $strongarm->value = 'main-menu:0';
  $export['menu_block_1_parent'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_1_sort';
  $strongarm->value = 0;
  $export['menu_block_1_sort'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_1_title_link';
  $strongarm->value = 0;
  $export['menu_block_1_title_link'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_ids';
  $strongarm->value = array(
    0 => 1,
  );
  $export['menu_block_ids'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_default_active_menus';
  $strongarm->value = array(
    0 => 'menu-categories',
    2 => 'main-menu',
    3 => 'management',
    4 => 'navigation',
    5 => 'user-menu',
    6 => 'devel',
  );
  $export['menu_default_active_menus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_expanded';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_expanded'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_masks';
  $strongarm->value = array(
    0 => 501,
    1 => 252,
    2 => 251,
    3 => 250,
    4 => 245,
    5 => 127,
    6 => 125,
    7 => 124,
    8 => 123,
    9 => 122,
    10 => 121,
    11 => 117,
    12 => 112,
    13 => 63,
    14 => 62,
    15 => 61,
    16 => 60,
    17 => 59,
    18 => 58,
    19 => 44,
    20 => 31,
    21 => 30,
    22 => 29,
    23 => 25,
    24 => 24,
    25 => 23,
    26 => 21,
    27 => 15,
    28 => 14,
    29 => 13,
    30 => 12,
    31 => 11,
    32 => 7,
    33 => 6,
    34 => 5,
    35 => 3,
    36 => 2,
    37 => 1,
  );
  $export['menu_masks'] = $strongarm;

  return $export;
}
