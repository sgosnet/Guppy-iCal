<?php
/*
	Plugin Version : Plugin for GuppY 4.5
	under CeCILL v2 Free Software Agreement
	Copyright (C) 2006-2007 by  HPSAM
	Web site = http://www.hpsam.info
	Adapté par Lud Bienaimé pour l'encodage en UTF-8 et le HTML5 
*/
if (stristr($_SERVER["SCRIPT_NAME"], "fr-pvlang.inc")) {
  header("location:../index.php");
  die();
}
$pv_error1 = "Impossible de vérifier la mise à jour car allow_url_fopen est désactivé.";
$pv_error2 = "La vérification de la mise à jour a échoué pour une raison inconnue.";
$pv_error3 = "Impossible de vérifier la mise à jour : Id non conforme.";
$pv_error4 = "Impossible de vérifier la mise à jour : Id non présent dans la base.";
$pv_error5 = "Impossible de vérifier la mise à jour : Id non active.";
$pv_ok1 = "Une nouvelle version est disponible.";
$pv_ok2 = "version ";
$pv_ok3 = " du ";
$pv_ok4 = "Vous utilisez déjà la dernière version.";
?>