<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>logout.jsp</title>
</head>
<body>
	<%
   Cookie[] cookies = request.getCookies();
    
   for(int i = 0; i < cookies.length; i++) {
       cookies[i].setMaxAge(0);
       response.addCookie(cookies[i]);
      }
      out.println("<script>" + "alert('로그아웃되었습니다.');" + "</script>" );
      out.println("<script>location.replace('login.jsp');</script>" );
      
   %>

</body>
</html>