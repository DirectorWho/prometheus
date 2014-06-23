<?php

/**
 * Implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Prometheus one column'),
  'category' => t('Columns: 1'),
  'icon' => 'icon.png',
  'theme' => 'prometheus-one-col',
  'css' => 'css/panels-layouts/prometheus-one-col.css',
  'regions' => array(
  'column' => t('Content'),
  ),
);
