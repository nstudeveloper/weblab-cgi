<html>
<head>
	<meta charset="UTF-8">
	<title>Quiz test</title>
</head>
<body>	
	<form action="/hello.cgi" method="post" >
			<label for="question-1">Вопрос 1. Сколько вариантов назначения стилей</label>
			<div id="question-1">
				<input type="radio" value="1" name="q1"> 1 </br>
				<input type="radio" value="2" name="q1"> 2 </br>
				<input type="radio" value="3" name="q1"> 3
			</div>

			<label for="question-2">Вопрос 2. CSS - это ?</label>
			<div id="question-2">
				<input type="radio" value="1" name="q2"> Cascade stylesheet </br>
				<input type="radio" value="2" name="q2"> Cascade script style</br>
				<input type="radio" value="3" name="q2"> Cascade style script
			</div>

			<label for="question-3">Вопрос 3. CSS предназначен для...</label>
			<div id="question-3">
				<input type="radio" value="1" name="q3"> Наполнения контента </br>
				<input type="radio" value="2" name="q3"> Для визуального оформления </br>
				<input type="radio" value="3" name="q3"> Для программирования DOM
			</div>

			<label for="question-3">Вопрос 4. Актуальная версия CSS </label>
			<div id="question-3">
				<input type="radio" value="1" name="q4"> 3.0 </br>
				<input type="radio" value="2" name="q4"> 2.59 </br>
				<input type="radio" value="3" name="q4"> 4.0
			</div>
		<input type="submit" value="Submit">
	</form>
</body>
</html>