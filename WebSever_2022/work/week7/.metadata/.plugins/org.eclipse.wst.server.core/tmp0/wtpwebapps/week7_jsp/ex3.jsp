<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Scripting tag</title>
</head>
<body>
	<%! String greeting = "Welcom to Web Shopping Mall";
		String tagline = "Welcom to Web Market";
	%>

	<h1><%= greeting %></h1>
	<h3><%= tagline %></h3>

</body>
</html>