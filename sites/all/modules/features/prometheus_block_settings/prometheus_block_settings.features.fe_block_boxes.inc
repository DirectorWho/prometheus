<?php
/**
 * @file
 * prometheus_block_settings.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function prometheus_block_settings_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Tips for using the installation profile.';
  $fe_block_boxes->format = 'advanced_full_html';
  $fe_block_boxes->machine_name = 'prometheus_intro';
  $fe_block_boxes->body = '<img alt="Sample pic" height="225" src="/sites/default/files/john-doe_0.jpg" width="350">
<p>Once Prometheus is stabilized, documentation will be written. Until then, keep in mind that the configuration for Prometheus is packaged up in Features. That\'s a good place to start if you need to&nbsp;figure&nbsp;out how/where things have been added. You can also visit the project page on <a href="https://github.com/friendlymachine/prometheus">GitHub</a> to open an issue or contact me.</p>
';

  $export['prometheus_intro'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Sample block content';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'prometheus_sample_block';
  $fe_block_boxes->body = '<p>Praesent sapien massa, convallis a pellentesque nec, egestas non nisi. Pellentesque in ipsum id orci porta dapibus. Vivamus magna justo, lacinia eget consectetur sed, convallis at tellus. Donec sollicitudin molestie malesuada.</p>
';

  $export['prometheus_sample_block'] = $fe_block_boxes;

  return $export;
}
