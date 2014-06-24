<?php
/**
 * @file
 * prometheus_block_settings.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function prometheus_block_settings_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-prometheus_intro'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'prometheus_intro',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'atlas' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'atlas',
        'weight' => 0,
      ),
    ),
    'title' => 'Tips to Get Started',
    'visibility' => 1,
  );

  $export['block-prometheus_sample_block'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'prometheus_sample_block',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'blog/diam-facilisi-meus-olim',
    'roles' => array(),
    'themes' => array(
      'atlas' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'atlas',
        'weight' => 0,
      ),
    ),
    'title' => 'Pellentesque in Ipsum',
    'visibility' => 1,
  );

  $export['menu-menu-categories'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'menu-categories',
    'module' => 'menu',
    'node_types' => array(),
    'pages' => 'blog*
tags/*',
    'roles' => array(),
    'themes' => array(
      'atlas' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'atlas',
        'weight' => -13,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  $export['menu_block-1'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 1,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'atlas' => array(
        'region' => 'menu',
        'status' => 1,
        'theme' => 'atlas',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
