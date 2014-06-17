<?php

/**
 * Implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Prometheus two 50% columns'),
  'category' => t('Columns: 2'),
  'icon' => 'icon.png',
  'theme' => 'prometheus-two-col',
  'css' => 'css/panels-layouts/prometheus-two-col.css',
  'regions' => array(
  'left' => t('Left column'),
  'right' => t('Right column'),
  ),
);
