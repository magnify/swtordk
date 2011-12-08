<?php
/**
 * @file swtor-account.tpl.php
 * Default theme implementation for swtor-account block
 *
 * Available variables:
 * - $links: The linkst listed in under account infomation.
 * - $links_raw: List of links in array, before theme('links', $links).
 * - $messages: The number of unread message.
 * - $links_message: Message links in array, before theme('links', $messages).
 *
 */
?>
<div id="swtor-account" class="swtor-account">
  <a class="account-name" href="/user/"><?php print t('Welcome') . '<span class="username">' . $username ?></span></a>
  <div class="content">
    <div class="item-list">
      <?php print $links ?>
    </div>
    <div class="bottom-wrapper">
      <?php print $messages ?>
      <a class="logout" href="/user/logout">Logout</a>
    </div>
  </div>
</div>