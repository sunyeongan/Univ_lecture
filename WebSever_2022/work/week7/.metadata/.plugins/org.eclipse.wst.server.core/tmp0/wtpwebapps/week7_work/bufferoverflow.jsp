<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>JSP 예제  bufferoverflow.jsp</title>
</head>
<body>
	<%@ page autoFlush="false" buffer="1kb" errorPage="error.jsp" %>	
	<%
		for(int i =1; i<25; i++) 
			out.println("남은 출력 버퍼크기  (out.getRemaining()) : " + out.getRemaining() + "<br>");
	%>
</body>
</html>