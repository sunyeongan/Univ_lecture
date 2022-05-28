<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Scripting Tag</title>
</head>
<body>
<%! String makeltLower(String data){
	return data.toLowerCase();
}
%>

<% out.println(makeltLower("Hello World!" + "<br>"));
	out.println("Hello World!".toUpperCase());
%>
</body>
</html>