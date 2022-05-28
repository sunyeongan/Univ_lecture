<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=EUC-KR">
<title>JSP 예제 request2.jsp</title>
</head>
<body>

<%request.setCharacterEncoding("euc-kr"); %>

<%
String studentNum = request.getParameter("studentNum");
String[] major = request.getParameterValues("major");
%>

<h2>학생 정보 입력 결과</h2>

학번 : <%=studentNum %><p>
전공 : <%
		if(major == null)
			out.println("전공없음");
		else{
			for(String eachmajor : major)
				out.println(eachmajor+" ");
		}
	%>
	
<h2>요청 정보</h2>
요청 방식 : <%=request.getMethod() %><p>
요청 URL : <%=request.getRequestURL() %><p>
요청 URI : <%=request.getRequestURI() %><p>
클라이언트 주소 : <%=request.getRemoteAddr() %><p>
클라이언트 호스트 : <%=request.getRemoteHost() %><p>
프로토콜 방식 : <%=request.getProtocol() %><p>
서버 이름 : <%=request.getServerName() %><p>
서버 포트번호 : <%=request.getServerPort() %><p>
</body>
</html>
</body>
</html>