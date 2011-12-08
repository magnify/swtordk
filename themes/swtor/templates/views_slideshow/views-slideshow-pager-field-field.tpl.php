<div class="pager">
  <?php if ($view->field[$field]->label()) { ?>
    <label class="field-label">
      <?php print $view->field[$field]->label(); ?>:
    </label>
  <?php } ?>
  <div class="pager-item">
    <?php print $view->style_plugin->rendered_fields[$count][$field]; ?>
  </div>
</div>
