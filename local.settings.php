<?php

$conf['cache_backends'][] = 'sites/www.swtor.dk/modules/contrib/memcache/memcache.inc';
$conf['cache_default_class'] = 'MemCacheDrupal';
$conf['cache_class_cache_form'] = 'DrupalDatabaseCache';


$conf['memcache_servers'] = array('localhost:11211' => 'default');
$conf['memcache_bins'] = array('cache' => 'default');
$conf['memcache_key_prefix'] = 'swtor';

$conf['memcache_options'] = array(
  Memcached::OPT_COMPRESSION => FALSE,
  Memcached::OPT_DISTRIBUTION => Memcached::DISTRIBUTION_CONSISTENT,
  Memcached::OPT_BINARY_PROTOCOL => TRUE,
);

//if ($_SERVER['HTTP_HOST'] == 'varnish.swtor.dk') {
  // Tell Drupal it's behind a proxy
  $conf['reverse_proxy'] = TRUE;

  // Tell Drupal what addresses the proxy server(s) use
  $conf['reverse_proxy_addresses'] = array('192.168.176.183');

  // Bypass Drupal bootstrap for anonymous users so that Drupal sets max-age > 0
  $conf['page_cache_invoke_hooks'] = FALSE;

  $conf['cache'] = 1;
//  $conf['cache_lifetime'] = 0;
  $conf['page_cache_maximum_age'] = 600;
//}
