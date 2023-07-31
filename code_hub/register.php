<?php include("head.html")
?>
<body>
<div class="register">
<table border="5px" cellpadding="30px" bordercolor="#00FF00" align="center" class="tab2">
<tr>
<th>REGISTER FORM</th>
</tr>
<tr>
<td>
<form action="connect.php" method="post">
<br><br>
<label for="username">USERNAME</label>
<input type="text" name="un" size="55" placeholder="enter your name" required /><br><br>
<label for="age">AGE</label>
<input type="number" size="10" name="a" /><br><br>
<label for="dob">DOB</label>
<input type="date" name="d" /><br><br>
<label for="gender">GENDER</label>
<input type="radio" value="male" name="g" />MALE
<input type="radio" value="female" name="g" />FEMALE
<input type="radio" value="others" name="g" />others<br><br>
<label for="email">EMAIL</label>
<input type="email" name="e" size="100" /><br><br>
<label for="password">password</label>
<input type="password" name="p" maxlength="8" /><br><br>
<label for="college">COLLEGE/UNIVERSITY  NAME(if a student)</label>
<input type="text" name="col" size="55" placeholder="enter your college/university/passed out/none" required><br><br>
<label for="dept">DEPARTMENT</label>
<select name="s">
<option value="EEE">EEE</option>
<option value="ece">ECE</option>
<option value="cse">cse</option>
<option value="it">it</option>
</select><br><br>
<label for="course">COURSE TO ENROLL</label>
<select name="co">
<option value="c" >c programming</option>
<option value="python">python programming</option>
<option value="javascript">javascript</option>
<option value="webdesign">webdesign</option>
</select><br><br>
<input type="submit" value="login">
<input type="reset" value="reset"><br><br>
</form>
</td>
</tr>
</table>
</div>
</body>
<?php include("footer.html")
?>