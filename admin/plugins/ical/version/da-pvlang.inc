<?php
/*
	Plugin Version : Plugin for GuppY 4.5
	under CeCILL v2 Free Software Agreement
	Copyright (C) 2006-2007 by  HPSAM
	Web site = http://www.hpsam.info

	Translated by HL : http://www.loeil-de-pique.com/
	Adapté par Lud Bienaimé pour l'encodage en UTF-8 et le HTML5 
*/
if (stristr($_SERVER["SCRIPT_NAME"], "da-pvlang.inc")) {
  header("location:../index.php");
  die();
}
$pv_error1 = "Kan ikke tjekke for opdateringer da allow_url_fopen ikke er aktiveret";
$pv_error2 = "Opdaterings tjek fejlede af ukendte årsager.";
$pv_error3 = "Kan ikke tjekke opdatering pga.: forkert ID.";
$pv_error4 = "Kan ikke tjekke opdatering pga.: ID ikke fundet i DB.";
$pv_error5 = "Kan ikke tjekke opdatering pga.: ID er lukket.";
$pv_ok1 = "En nyere ver. er nu tilgængelig.";
$pv_ok2 = " Version ";
$pv_ok3 = " Dato ";
$pv_ok4 = " ..| Dette _<i>er</i>_ sidste nye version |.. ";
?>