<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 */
?>
<div class="top-wrapper panel-wrapper">
    <div class="top-left grid-8">
      <?php print $content['top_left']; ?>
    </div>
    <div class="top-right sidebar-second grid-4">
      <?php print $content['top_right']; ?>
    </div>
</div>
<div class="center-wrapper panel-wrapper">
    <div class="center-left">
      <?php print $content['center_left']; ?>
    </div>
    <div class="center-right sidebar-second grid-4">
      <?php print $content['center_right']; ?>
    </div>
</div>
<div class="bottom-wrapper panel-wrapper">
    <div class="bottom-left grid-8">
      <?php print $content['bottom_left']; ?>
    </div>
    <div class="bottom-right sidebar-second grid-4">
      <?php print $content['bottom_right']; ?>
    </div>
</div>