<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
	request.setCharacterEncoding("euc-kr");
%>

<%

	

	String adminId = "나관리";
	String adminPassword = "1234";
	String id = request.getParameter("id");
	String passwd = request.getParameter("passwd");
	
%>

<% 
	if(adminId.equalsIgnoreCase(id) && adminPassword.equalsIgnoreCase(passwd)){
		out.println("이름 : " + id + "<p>");
		out.println("클라이언트 IP : " + request.getRemoteAddr() + "<p>");
		out.println("요청 정보 길이 : " + request.getContentLength() + "<p>");
		out.println("요청 정보 전송방식  : " + request.getMethod() + "<p>");
		out.println("요청 URI : " + request.getRequestURI() + "<p>");
		out.println("서버 이름  : " + request.getServerName() + "<p>");
		out.println("서버 포트 : " + request.getServerPort() + "<p>");
	}
	else{ // 맞으면 요청정보 출력 
		out.println("["+id+"]님은 관리자가 아닙니다.");
		
			
		}
	
	
%>



</body>
</html>