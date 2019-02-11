all: ConfigParser.class Task.class AtCron.class

ConfigParser.class: ConfigParser.java
	javac $<

Task.class: Task.java
	javac $<

AtCron.class: AtCron.java
	javac $<

run: all
	java AtCron aconfigfile 

clean:
	rm ConfigParser.class Task.class AtCron.class
