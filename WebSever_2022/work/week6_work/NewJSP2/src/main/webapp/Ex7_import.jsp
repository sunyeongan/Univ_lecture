<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<h2> page 지시자의 import 속</h2>
	<%@ page import="java.util.Date" %>
	현재 시작 : <%= new Date().toLocaleString() %>
</body>
</html>