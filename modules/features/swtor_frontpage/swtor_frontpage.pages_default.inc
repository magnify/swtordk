<?php
/**
 * @file
 * swtor_frontpage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function swtor_frontpage_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'frontpage';
  $page->task = 'page';
  $page->admin_title = 'Frontpage';
  $page->admin_description = '';
  $page->path = 'front';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_frontpage_panel_context_2';
  $handler->task = 'page';
  $handler->subtask = 'frontpage';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'frontpage',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display;
  $display->layout = 'twocol_stacked_frontpage';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 2,
        ),
        'parent' => NULL,
      ),
      2 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 3,
          1 => 6,
          2 => 10,
        ),
        'class' => 'grid-12',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 4,
          1 => 5,
        ),
        'parent' => '2',
        'class' => '',
      ),
      4 => array(
        'type' => 'column',
        'width' => '66.71851224907489',
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 11,
        ),
        'class' => 'column grid-8',
      ),
      5 => array(
        'type' => 'column',
        'width' => '33.28148775092511',
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 16,
        ),
        'class' => 'column sidebar grid-4',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 9,
          1 => 8,
          2 => 7,
        ),
        'parent' => '2',
        'class' => 'grid-12',
      ),
      7 => array(
        'type' => 'column',
        'width' => '33.33126116900221',
        'width_type' => '%',
        'parent' => '6',
        'children' => array(
          0 => 15,
        ),
        'class' => 'grid-4',
      ),
      8 => array(
        'type' => 'column',
        'width' => '33.33464449899842',
        'width_type' => '%',
        'parent' => '6',
        'children' => array(
          0 => 14,
        ),
        'class' => 'grid-4',
      ),
      9 => array(
        'type' => 'column',
        'width' => '33.33409433199936',
        'width_type' => '%',
        'parent' => '6',
        'children' => array(
          0 => 13,
        ),
        'class' => 'grid-4',
      ),
      10 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'front_third_center',
          1 => 'front_third',
        ),
        'parent' => '2',
        'class' => 'grid-12',
      ),
      11 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'front_first_left',
        ),
        'parent' => '4',
        'class' => '',
      ),
      'front_first_left' => array(
        'type' => 'region',
        'title' => 'front-first-left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '11',
        'class' => '',
      ),
      13 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'front_second_left',
        ),
        'parent' => '9',
        'class' => '',
      ),
      14 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'front_second_center',
        ),
        'parent' => '8',
        'class' => '',
      ),
      15 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'front_second_right',
        ),
        'parent' => '7',
        'class' => '',
      ),
      'front_second_left' => array(
        'type' => 'region',
        'title' => 'front-second-left',
        'width' => 100,
        'width_type' => '%',
        'parent' => '13',
        'class' => '',
      ),
      'front_second_center' => array(
        'type' => 'region',
        'title' => 'front-second-center',
        'width' => 100,
        'width_type' => '%',
        'parent' => '14',
        'class' => '',
      ),
      'front_second_right' => array(
        'type' => 'region',
        'title' => 'front-second-right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '15',
        'class' => '',
      ),
      'front_third' => array(
        'type' => 'region',
        'title' => 'front-third-right',
        'width' => '33.250904970413146',
        'width_type' => '%',
        'parent' => '10',
        'class' => 'column sidebar grid-4',
      ),
      16 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'front_first_right',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'front_first_right' => array(
        'type' => 'region',
        'title' => 'front-first-right',
        'width' => 100,
        'width_type' => '%',
        'parent' => '16',
        'class' => 'column sidebar grid-4',
      ),
      'front_third_center' => array(
        'type' => 'region',
        'title' => 'front-third-center',
        'width' => '66.74909502958685',
        'width_type' => '%',
        'parent' => '10',
        'class' => 'column grid-8',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
      'front_second' => NULL,
      'front_first_left' => NULL,
      'front_first_right' => NULL,
      'front_second_left' => NULL,
      'front_second_center' => NULL,
      'front_second_right' => NULL,
      'front_third' => NULL,
      'front_third_center' => NULL,
      'top_left' => NULL,
      'top_right' => NULL,
      'center_left' => NULL,
      'center_right' => NULL,
      'bottom_left' => NULL,
      'bottom_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'bottom_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'frontpage-frontpage_articles_bottom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'offset' => '3',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['bottom_left'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'bottom_right';
    $pane->type = 'block';
    $pane->subtype = 'block-5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-2'] = $pane;
    $display->panels['bottom_right'][0] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'center_left';
    $pane->type = 'block';
    $pane->subtype = 'adsense_managed-0';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grid-4',
    );
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['center_left'][0] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'center_left';
    $pane->type = 'block';
    $pane->subtype = 'adsense_managed-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'grid-4',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-4'] = $pane;
    $display->panels['center_left'][1] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'center_right';
    $pane->type = 'block';
    $pane->subtype = 'adsense_managed-2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-5'] = $pane;
    $display->panels['center_right'][0] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'top_left';
    $pane->type = 'views';
    $pane->subtype = 'featured_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-6'] = $pane;
    $display->panels['top_left'][0] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'top_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'frontpage-frontpage_articles_top';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '4',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-7'] = $pane;
    $display->panels['top_left'][1] = 'new-7';
    $pane = new stdClass;
    $pane->pid = 'new-8';
    $pane->panel = 'top_right';
    $pane->type = 'views';
    $pane->subtype = 'front_page_forum_topics';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-8'] = $pane;
    $display->panels['top_right'][0] = 'new-8';
    $pane = new stdClass;
    $pane->pid = 'new-9';
    $pane->panel = 'top_right';
    $pane->type = 'block';
    $pane->subtype = 'adsense_managed-4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'adsense',
    );
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-9'] = $pane;
    $display->panels['top_right'][1] = 'new-9';
    $pane = new stdClass;
    $pane->pid = 'new-10';
    $pane->panel = 'top_right';
    $pane->type = 'views';
    $pane->subtype = 'front_page_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'block',
      'override_title' => 1,
      'override_title_text' => 'Seneste kommentar',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-10'] = $pane;
    $display->panels['top_right'][2] = 'new-10';
    $pane = new stdClass;
    $pane->pid = 'new-11';
    $pane->panel = 'top_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'external_news-external_news_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'items_per_page' => '5',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-11'] = $pane;
    $display->panels['top_right'][3] = 'new-11';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['frontpage'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'holonet_frontpage';
  $page->task = 'page';
  $page->admin_title = 'Holonet frontpage';
  $page->admin_description = '';
  $page->path = 'holonet';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Wiki',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_holonet_frontpage_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'holonet_frontpage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Velkommen til HoloNettet';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Sith klasser',
      'body' => '<ul>
<li><a href="http://www.swtor.com/info/holonet/classes/bounty-hunter" target="_blank">Bounty Hunter</a></li>
<li><a href="http://www.swtor.com/info/holonet/classes/sith-warrior" target="_blank">Sith Warrior</a></li>
<li><a href="http://www.swtor.com/info/holonet/classes/sith-inquisitor" target="_blank">Sith Inquisitor</a></li>
<li><a href="http://www.swtor.com/info/holonet/classes/imperial-agent" target="_blank">Imperial Agent</a></li>
</ul>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['left'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Planeter',
      'body' => '<ul>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/tython" target="_blank" title="Tython">Tython</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/korriban" target="_blank" title="Korriban">Korriban</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/hutta" target="_blank" title="Hutta">Hutta</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/ord-mantell" target="_blank" title="Ord Mantell">Ord Mantell</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/coruscant" target="_blank" title="Coruscant">Coruscant</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/balmorra" target="_blank" title="Balmorra">Balmorra</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/alderaan" target="_blank" title="Alderaan">Alderaan</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/tatooine" target="_blank" title="Tatooine">Tatooine</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/dromund-kaas" target="_blank" title="Dromund Kaas">Dromund Kaas</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/taris" target="_blank" title="Taris">Taris</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/belsavis" target="_blank" title="Belsavis">Belsavis</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/voss" target="_blank" title="Voss">Voss</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/hoth" target="_blank" title="Hoth">Hoth</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/nar-shaddaa" target="_blank" title="Nar Shaddaa">Nar Shaddaa</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/corellia" target="_blank" title="Corellia">Corellia</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/ilum" target="_blank" title="Ilum">Ilum</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/planets/quesh" target="_blank" title="Quesh">Quesh</a>
  </li>
</ul>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['left'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Tidslinjen',
      'body' => '<table>
      <tbody>
        <tr>
          <td>
            ATC 0
          </td>
          <td>
            - <a href="/Timeline/The_Treaty_Of_Corruscant" target="_blank" title="Timeline/The Treaty Of Corruscant">The Treaty Of Corruscant</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 7
          </td>
          <td>
            - <a href="/Timeline/The_Mandalorian_Blockade_Is_Broken" target="_blank" title="Timeline/The Mandalorian Blockade Is Broken">The Mandalorian Blockade Is Broken</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 8
          </td>
          <td>
            - <a href="/Timeline/The_Return_Of_The_Mandalorians" target="_blank" title="Timeline/The Return Of The Mandalorians">The Return Of The Mandalorians</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 14
          </td>
          <td>
            - <a href="/Timeline/The_Empire_Changes_Strategy" target="_blank" title="Timeline/The Empire Changes Strategy">The Empire Changes Strategy</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 18
          </td>
          <td>
            - <a href="/Timeline/The_Battle_Of_Bothawui" target="_blank" title="Timeline/The Battle Of Bothawui">The Battle Of Bothawui</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 28
          </td>
          <td>
            - <a href="/Timeline/Onslaught_Of_The_Sith_Empire" target="_blank" title="Timeline/Onslaught Of The Sith Empire">Onslaught Of The Sith Empire</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 103
          </td>
          <td>
            - <a href="/Timeline/Peace_For_The_Republic%3F" target="_blank" title="Timeline/Peace For The Republic?">Peace For The Republic?</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 303
          </td>
          <td>
            - <a href="/Timeline/The_Jedi_Civil_War" target="_blank" title="Timeline/The Jedi Civil War">The Jedi Civil War</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 311
          </td>
          <td>
            - <a href="/Timeline/The_Mandalorian_Wars" target="_blank" title="Timeline/The Mandalorian Wars">The Mandalorian Wars</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 347
          </td>
          <td>
            - <a href="/Timeline/The_Exar_Kun_War" target="_blank" title="Timeline/The Exar Kun War">The Exar Kun War</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 1251
          </td>
          <td>
            - <a href="/Timeline/Rebirth_Of_The_Sith_Empire" target="_blank" title="Timeline/Rebirth Of The Sith Empire">Rebirth Of The Sith Empire</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 1347
          </td>
          <td>
            - <a href="/Timeline/The_Great_Hyperspace_War" target="_blank" title="Timeline/The Great Hyperspace War">The Great Hyperspace War</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 3247
          </td>
          <td>
            - <a href="http://www.wikiswtor.com/Timeline/The_First_Dark_Sith_Lords_On_Korriban" target="_blank" title="Timeline/The First Dark Sith Lords On Korriban">The First Dark Sith Lords On Korriban</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 3347
          </td>
          <td>
            - <a href="http://www.wikiswtor.com/Timeline/The_2nd_Great_Jedi_Schism" target="_blank" title="Timeline/The 2nd Great Jedi Schism">he 2nd Great Jedi Schism</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 21300
          </td>
          <td>
            - <a href="http://www.wikiswtor.com/Timeline/The_Jedi_Join_The_Republic" target="_blank" title="Timeline/The Jedi Join The Republic">The Jedi Join The Republic</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 21400
          </td>
          <td>
            - <a href="http://www.wikiswtor.com/Timeline/Founding_Of_The_Republic" target="_blank" title="Timeline/Founding Of The Republic">Founding Of The Republic</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 22130
          </td>
          <td>
            - <a href="http://www.wikiswtor.com/Timeline/The_Jedi_Order_Is_Established" target="_blank" title="Timeline/The Jedi Order Is Established">The Jedi Order Is Established</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 22140
          </td>
          <td>
            - <a href="http://www.wikiswtor.com/Timeline/The_Force_War_On_Tython" target="_blank" title="Timeline/The Force War On Tython">The Force War On Tython</a>
          </td>
        </tr>
        <tr>
          <td>
            BTC 32800
          </td>
          <td>
            - <a href="http://www.wikiswtor.com/Timeline/Force_%22Discovered%22_On_Tython" target="_blank" title="Timeline/Force &quot;Discovered&quot; On Tython">Force "Discovered" On Tython</a>
          </td>
        </tr>
      </tbody>
    </table>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-3'] = $pane;
    $display->panels['left'][2] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'left';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Inhabitants',
      'body' => 'En link liste her
',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-4'] = $pane;
    $display->panels['left'][3] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Republic klasser',
      'body' => '<ul>
<li><a href="http://www.swtor.com/info/holonet/classes/trooper" target="_blank">Trooper</a></li>
<li><a href="http://www.swtor.com/info/holonet/classes/jedi-knight" target="_blank">Jedi Knight</a></li>
<li><a href="http://www.swtor.com/info/holonet/classes/jedi-consular" target="_blank">Jedi Consular</a></li>
<li><a href="http://www.swtor.com/info/holonet/classes/smuggler" target="_blank">Smuggler</a></li>
</ul>',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-5'] = $pane;
    $display->panels['right'][0] = 'new-5';
    $pane = new stdClass;
    $pane->pid = 'new-6';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Tilhørsforhold & Fraktioner',
      'title' => '',
      'body' => '<h2>Tilhørsforhold</h2>
<ul>
  <li>
    <a href="http://www.swtor.com/info/holonet/allegiances/galactic-republic" target="_blank" title="The Galactic Republic">The Galactic Republic</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/allegiances/sith-empire" target="_blank" title="The Sith Empire">The Sith Empire</a>
  </li>
</ul>
<h2>Fraktioner</h2>
<ul>
  <li>
    <a href="http://www.swtor.com/info/holonet/allegiances/jedi-order" target="_blank" title="The Jedi Order">The Jedi Order</a>
  </li>
  <li>
    <a href="http://www.swtor.com/info/holonet/allegiances/sith-lords" target="_blank" title="The Sith Lords">The Sith Lords</a>
  </li>
</ul>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-6'] = $pane;
    $display->panels['right'][1] = 'new-6';
    $pane = new stdClass;
    $pane->pid = 'new-7';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Biografier - Imperiet',
      'body' => '<ul>
  <li><a href="http://www.swtor.com/info/holonet/biographies/khem-val" target="_blank">Khem Val</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/darth-jadus" target="_blank">Darth Jadus</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/keeper" target="_blank">Keeper</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/darth-malgus" target="_blank">Darth Malgus</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/grand-moff-kilran" target="_blank">Grand Moff Kilran</a></li>
</ul>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $display->content['new-7'] = $pane;
    $display->panels['right'][2] = 'new-7';
    $pane = new stdClass;
    $pane->pid = 'new-8';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Biografier - Uafhængige',
      'body' => '<ul>
  <li><a href="http://www.swtor.com/info/holonet/biographies/mako" target="_blank">Mako</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/jewla-nightbringer" target="_blank">Jewla Nightbringer</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/tanno-vik" target="_blank">Tanno Vik</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/kaliyo-djannis" target="_blank">Kaliyo Djannis</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/bouris-ulgo" target="_blank">Bouris Ulgo</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/bowdaar" target="_blank">Bowdaar</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/vette" target="_blank">Vette</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/mandalore" target="_blank">Mandalore</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/nemro-hutt" target="_blank">Nemro the Hutt</a></li>
</ul>
',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $display->content['new-8'] = $pane;
    $display->panels['right'][3] = 'new-8';
    $pane = new stdClass;
    $pane->pid = 'new-9';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Biografier - Republikken',
      'body' => '<ul>
  <li><a href="http://www.swtor.com/info/holonet/biographies/supreme-chancellor-janarus" target="_blank">Supreme Chancellor Janarus</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/diab-duin" target="_blank">Diab Duin</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/t7-o1" target="_blank">T7-O1</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/general-garza" target="_blank">General Garza</a></li>
  <li><a href="http://www.swtor.com/info/holonet/biographies/jedi-grand-master-satele-shan" target="_blank">Jedi Grand Master Satele Shan</a></li>
</ul>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $display->content['new-9'] = $pane;
    $display->panels['right'][4] = 'new-9';
    $pane = new stdClass;
    $pane->pid = 'new-10';
    $pane->panel = 'right';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Rumskibe',
      'body' => '<ul>
  <li><a href="http://www.swtor.com/info/holonet/starships/d5-mantis" target="_blank">D5-Mantis</a></li>
  <li><a href="http://www.swtor.com/info/holonet/starships/fury" target="_blank">Fury</a></li>
  <li><a href="http://www.swtor.com/info/holonet/starships/bt-7-thunderclap" target="_blank">BT-7 Thunderclap</a></li>
  <li><a href="http://www.swtor.com/info/holonet/starships/x-70b-phantom" target="_blank">X-70B Phantom</a></li>
  <li><a href="http://www.swtor.com/info/holonet/starships/xs-freighter" target="_blank">X5 Freighter</a></li>
  <li><a href="http://www.swtor.com/info/holonet/starships/defender" target="_blank">Defender</a></li>
</ul>
',
      'format' => 'filtered_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $display->content['new-10'] = $pane;
    $display->panels['right'][5] = 'new-10';
    $pane = new stdClass;
    $pane->pid = 'new-11';
    $pane->panel = 'top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => 'This interface facilitates queries to any database connected to the galactic communications grid. Detailed information and imagery regarding prominent political bodies, professional classifications and planetary systems will be available here as it comes online. Privileged access to historical records from the Jedi Archives is also permitted. Additional knowledge bases are scheduled to be linked to the system in the future',
      'format' => 'plain_text',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-11'] = $pane;
    $display->panels['top'][0] = 'new-11';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-11';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['holonet_frontpage'] = $page;

 return $pages;

}
