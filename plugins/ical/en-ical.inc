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

if (stristr($_SERVER['SCRIPT_NAME'], 'en-ical.inc')) {
    header('location:index.php');
    die();
}

$ical[1] = "Admin -  iCal Plugin";
$ical[2] = "iCal";
$ical[3] = "This plugin is used to share calendar in iCal format.";
$ical[4] = "Activate $ical[2] plugin";
$ical[5] = "iCal [".$lang[0]."] is available at ";
$ical[6] = "iCal [".$lang[1]."] is available at ";
$ical[7] = "Current Time Zone : '".$site['TZ']."'";

$ical[20] = "Uninstall iCal";


