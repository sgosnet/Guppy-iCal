<?php
/*
	Plugin Version : Plugin for GuppY is GPL  Copyright (C) 2006 by  HPSAM
	Web site = http://www.hpsam.info
	Translated by HL : http://www.loeil-de-pique.com/
	Adapté par Lud Bienaimé pour l'encodage en UTF-8 et le HTML5 
*/
if (stristr($_SERVER["SCRIPT_NAME"], "sl-pvlang.inc")) {
  header("location:../index.php");
  die();
}
$pv_error1 = "Ni dostopa do posodobitve - allow_url_fopen je izkljuèen.";
$pv_error2 = "Dostop do posodobitve ni uspel iz neznanega vzroka.";
$pv_error3 = "Ni dostopa do posodobitve  : nepravilni Id.";
$pv_error4 = "Ni dostopa do posodobitve  : Id ni najden v bazi.";
$pv_error5 = "Ni dostopa do posodobitve  : Id je izkljuèen.";
$pv_ok1 = "Nova verzija je na razpolago.";
$pv_ok2 = "verzija ";
$pv_ok3 = " Datum ";
$pv_ok4 = "Imate najnovejšo verzijo.";
?>