<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>login_pro</title>
</head>
<body>
	<%
		request.setCharacterEncoding("utf-8");
	
		String user_id = request.getParameter("id");
		String user_pw = request.getParameter("passwd");
		
		
		
		if(user_id.equals("kim") && user_pw.equals("1234")){
			Cookie cookie_id = new Cookie("userID", user_id);
			
			response.addCookie(cookie_id); // 서버 -> 클라이언트 
			
			out.println("[" + user_id + "]님 반갑습니다.<p>");
			out.println("<a href=my.jsp>"+user_id + "님의 관리 페이지로 이동합니다. </a><br>");
			out.println("<a href=logout.jsp>"+ "로그아웃합니다</a><br>");
		}else{
			out.println("<script>" + "alert('아이디와 패스워드가 다릅니다.');" + "history.back();" + "</script>");
		}
		%>
	
	
</body>
</html>