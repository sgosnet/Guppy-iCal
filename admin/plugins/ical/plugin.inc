<?php
/*******************************************************************************
 *   Plugin iCal pour Guppy
 *******************************************************************************
 *   Développé par Stéphane GOSNET
 *   Web site = http://stephane.gosnet.free.fr
 *   e-mail   = stegos@free.fr
 *******************************************************************************
 *   Version  :
 * v1.0 (06/2016) : Version initiale.
 ******************************************************************************/

if (stristr($_SERVER['SCRIPT_NAME'], 'plugin.inc')) {
    header('location:../index.php');
    die();
}

if (is_file(CHEMIN.'plugins/ical/'.$lng.'-ical.inc')) {
    include CHEMIN.'plugins/ical/'.$lng.'-ical.inc';
} else {
    include CHEMIN.'plugins/ical/en-ical.inc';
}

$plugin_admin_name = $ical[2];
$plugin_admin_url  = 'ical/ical';
$plugin_admin_icon = 'ical/ical.gif';

$plugin_datas_uninstall = array(
   'dirs' => array(
   'plugins/ical',
   'documentation/plugins/ical',
   'admin/plugins/ical'
   ),
   'unreg' => 'plg_ical',
   'include' => 'admin/plugins/ical/uninstall.inc',
   'function' => 'ap_uninstall'
);

