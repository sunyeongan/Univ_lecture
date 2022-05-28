package week12;

public class stuBean {
	
	private String id;
	private String sname;
	private String call;
	private int year;
	private int age;
	
	private String pw;
	private String mail;
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getSname() {
		return sname;
	}
	public void setSname(String sname) {
		this.sname = sname;
	}
	public String getCall() {
		return call;
	}
	public void setCall(String call) {
		this.call = call;
	}
	
	
	public int getAge() {
		int age = 0;
		if(year == 1995)
			age = 27;
		else if(year == 1996)
			age = 26;
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	
	public int getYear() {
		return year;
	}
	public void setYear(int year) {
		this.year = year;
	}
	
	public String getPw() {
		return pw;
	}
	public void setPw(String pw) {
		this.pw = pw;
	}
	public String getMail() {
		return mail;
	}
	public void setMail(String mail) {
		this.mail = mail;
	}
	

}
