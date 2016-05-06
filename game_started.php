<?php
session_start();
if(!is_numeric($_SESSION['team_cnt']))
{
	header("location: index.php");
}
?>
<html>
<head>
<title>Game started!</title>
</head>
<body>
<form action="end_game.php" method="POST" name="end_game_form">
<?php
$var = $_SESSION['team_cnt'];
echo "<input type='hidden' value='$var' name='team_cnt'/>";
?>
<input type="submit" value="End Game!" name="sub_end"/>
</form>
</body>
</html>