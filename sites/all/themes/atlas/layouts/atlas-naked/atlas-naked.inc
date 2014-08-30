<?php

/**
 * Implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Atlas naked layout'),
  'category' => t('Columns: 1'),
  'icon' => 'icon.png',
  'theme' => 'atlas-naked',
  'regions' => array(
  'column' => t('Content'),
  ),
);
