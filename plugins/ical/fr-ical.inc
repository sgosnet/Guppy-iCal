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

if (stristr($_SERVER['SCRIPT_NAME'], 'fr-ical.inc')) {
    header('location:index.php');
    die();
}

$ical[1] = "Admin - Plugin iCal";
$ical[2] = "iCal";
$ical[3] = "Ce plugin permet de partager le calendrier Guppy au format ICS.";
$ical[4] = "Activer le plugin $ical[2]";
$ical[5] = "Le calendrier iCal [".$lang[0]."] est accessible à l'adresse ";
$ical[6] = "Le calendrier iCal [".$lang[1]."] est accessible à l'adresse ";
$ical[7] = "Time Zone courante : '".$site['TZ']."'";

$ical[20] = "Désinstaller iCal";
