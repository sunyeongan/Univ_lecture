<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<h2>학생 정보 입력 </h2>
<form method = "post" action = "request2.jsp">

	성명 : <input type = "text" name = "name"><p>
	학번 : <input type = "text" name = "studentNum"><p>
	성별 : 	남자 <input type = "radio" name = "sex" value = "남자 " checked = "checked">
			여자 <input type = "radio" name = "sex" value = "여자 "><p>
	국적 : <select name = "country">
			<option SELECTED value = "대한민국"> 대한민국 </option>
				
	
	</select><p>
	<input type = "submit" value = "보내기">
</form>

</body>
</html>