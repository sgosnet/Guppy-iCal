<?php
/*
	Plugin Version : Plugin for GuppY 4.5
	under CeCILL v2 Free Software Agreement
	Copyright (C) 2006-2007 by  HPSAM
	Web site = http://www.hpsam.info

	Translated by HL : http://www.loeil-de-pique.com/
	Adapté par Lud Bienaimé pour l'encodage en UTF-8 et le HTML5 
*/
if (stristr($_SERVER["SCRIPT_NAME"], "en-pvlang.inc")) {
  header("location:../index.php");
  die();
}
$pv_error1 = "Unable to check for upgrade since allow_url_fopen is disabled.";
$pv_error2 = "Check for upgrade failed for unknown reasons.";
$pv_error3 = "Unable to check for upgrade  : incorrect Id.";
$pv_error4 = "Unable to check for upgrade  : Id not found in the database.";
$pv_error5 = "Unable to check for upgrade  : Id disabled.";
$pv_ok1 = "A new version is available.";
$pv_ok2 = "version ";
$pv_ok3 = " Date ";
$pv_ok4 = "You are running the latest version.";
?>