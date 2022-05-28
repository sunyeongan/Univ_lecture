<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>JSP 예제 declaration.jsp</title>
</head>
<body>
	<%! double radius = 4.8; %>
	<%!
		public double getArea(double r){
			return r * r * 3.14;
		}
	%>
	반지름이 <%= radius %>인 원의면적은<%= getArea(radius) %>이다.

</body>
</html>