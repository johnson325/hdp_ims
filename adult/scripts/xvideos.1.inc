<?php
	$link = $search = 'http://www.xvideos.com';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<div id="categories"', $html);

	$videos = explode('<li>', ($htmlToExplode = $htmlBody[1]));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

//	$myImgHeight  = 35;
?>
