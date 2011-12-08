<?php

// Plugin definition
$plugin = array(
  'title' => t('Two column stacked (frontpage)'),
  'category' => t('Columns: 2'),
  'icon' => 'twocol_stacked_frontpage.png',
  'theme' => 'panels_twocol_stacked_frontpage',
  'css' => 'twocol_stacked_frontpage.css',
  'regions' => array(
    'top_left' => t('Top left'),
    'top_right' => t('Top right'),
    'center_left' => t('Center left'),
    'center_right' => t('Center right'),
    'bottom_left' => t('Bottom left'),
    'bottom_right' => t('Bottom right')
  ),
);