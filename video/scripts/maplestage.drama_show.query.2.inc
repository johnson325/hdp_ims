<?php
	$sortedVideos = array();

	// 0: show; 1: drama
	$type = 1;
	if (strcmp($myBaseName, 'maplestage.show') == 0) {
		$type = 0;
	}

	$siteURLprefix = 'http://maplestage.com';
	foreach($videos as $video) {
		if ($type == 0)
			$title = trim(str_between($video, 'href="/show/', '/">'));
		else
			$title = trim(str_between($video, 'href="/drama/', '/">'));
		$title = convertUnicodePoints($title);
		$data  = '';
		$link  = trim(str_between($video, ' href="', '"'));
		if (strpos($link, 'http://') === false)
			$link = $siteURLprefix . $link;
		$image = '';
		$note  = '';
		$extra = '';

		$sortedVideos[] = array(
			$title,
			$data,
			$link,
			$image,
			$note,
			$extra,
		);
	}

	if ($type == 0) {
		usort($sortedVideos, "yp_cmp_videos_maplestage_show");
	}
	else {
		usort($sortedVideos, "yp_cmp_videos_maplestage_drama");
	}

	foreach($sortedVideos as $video) {
		$title = $video[0];
		$data  = $video[1];
		$link  = $video[2];
		$image = $video[3];
		$note  = $video[4];
		$extra = $video[5];

		$pageStart = 1;
		$queryLevel = '.query.query';
		include('04_query.inc');
	}
?>
<?php
	function yp_cmp_videos_maplestage_drama($a, $b) {
		// Compare their Chinese titles
		$aexp = explode('/', $a[0]);
		$bexp = explode('/', $b[0]);
		return yp_cmp_strings_length_first(trim($aexp[0]), trim($bexp[0]));
	}
	function yp_cmp_videos_maplestage_show($a, $b) {
		return yp_cmp_strings_length_first(trim($a[0]), trim($b[0]));
	}
?>
