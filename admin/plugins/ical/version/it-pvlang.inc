<?php
/*
	Plugin Version : Plugin for GuppY 4.5
	under CeCILL v2 Free Software Agreement
	Copyright (C) 2006-2007 by  HPSAM
	Web site = http://www.hpsam.info

	Traduttore Valkiro : http://www.valkiro.altervista.org/index.php
	Adapté par Lud Bienaimé pour l'encodage en UTF-8 et le HTML5 
*/
if (stristr($_SERVER["SCRIPT_NAME"], "it-pvlang.inc")) {
  header("location:../index.php");
  die();
}
$pv_error1 = "Impossibile verificare il collocamento aggiornato perché allow_url_fopen è disattivato.";
$pv_error2 = "La verifica del collocamento aggiornato è fallita per una ragione sconosciuta.";
$pv_error3 = "Impossibile verificare il collocamento aggiornato: Id non conforme.";
$pv_error4 = "Impossibile verificare il collocamento aggiornato: Id non presente nel data basee.";
$pv_error5 = "Impossibile verificare il collocamento aggiornato: Id non attiva.";
$pv_ok1 = "Una nuova versione è disponibile.";
$pv_ok2 = "versione ";
$pv_ok3 = " del ";
$pv_ok4 = "Utilizzate già l'ultima versione.";
?>