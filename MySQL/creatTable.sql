mysql -h localhost -u root -p

DROP TABLE IF EXISTS `employee`;
CREATE TABLE `employee` (
  `user_id` varchar(50) NOT NULL,
  `user_name` varchar(50) NOT NULL,
  `telephone` varchar(50) DEFAULT NULL,
  `mail` varchar(50) NOT NULL,
  `user_status` varchar(50) NOT NULL,
  PRIMARY KEY (`user_id`),
  FOREIGN KEY (`user_id`) REFERENCES `employee_auth` (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `auth`;
CREATE TABLE `auth` (
  `auth_id` int(11) NOT NULL AUTO_INCREMENT,
  `auth_name` varchar(50) NOT NULL,
  PRIMARY KEY (`auth_id`),
  FOREIGN KEY (`auth_id`) REFERENCES `employee_auth` (`auth_id`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `employee_auth`;
CREATE TABLE `employee_auth` (
  `user_id` varchar(50) NOT NULL,
  `auth_id` int(11) NOT NULL,
  PRIMARY KEY (`user_id`,`auth_id`),
  KEY `user_id` (`user_id`),
  KEY `auth_id` (`auth_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;


INSERT INTO employee_auth (user_id, auth_id) VALUES ("zhangsan", 1);
INSERT INTO employee_auth (user_id, auth_id) VALUES ("lisi", 1);
INSERT INTO employee_auth (user_id, auth_id) VALUES ("wangwu", 2);
INSERT INTO employee_auth (user_id, auth_id) VALUES ("wangwei", 3);
INSERT INTO employee_auth (user_id, auth_id) VALUES ("wangfang", 3);
INSERT INTO employee_auth (user_id, auth_id) VALUES ("wangfang", 4);
INSERT INTO employee_auth (user_id, auth_id) VALUES ("zhangmin", 3);
INSERT INTO employee_auth (user_id, auth_id) VALUES ("zhangmin", 5);
INSERT INTO employee_auth (user_id, auth_id) VALUES ("zhangwei", 3);
INSERT INTO employee_auth (user_id, auth_id) VALUES ("lijun", 3);
INSERT INTO auth(auth_id,auth_name) VALUES (1,"管理员");
INSERT INTO auth(auth_id,auth_name) VALUES (2,"项目经理");
INSERT INTO auth(auth_id,auth_name) VALUES (3,"普通用户");
INSERT INTO auth(auth_id,auth_name) VALUES (4,"临时测试");
INSERT INTO auth(auth_id,auth_name) VALUES (5,"临时支持");
INSERT INTO employee(user_id,user_name,telephone,mail,user_status) VALUES ("zhangsan","张三","1","zhangsan@mail.com","在职");
INSERT INTO employee(user_id,user_name,telephone,mail,user_status) VALUES ("lisi","李四","2","lisi@mail.com","在职");
INSERT INTO employee(user_id,user_name,telephone,mail,user_status) VALUES ("wangwu","王五","3","wangwu@mail.com","在职");
INSERT INTO employee(user_id,user_name,telephone,mail,user_status) VALUES ("wangwei","王伟","4","wangwei@mail.com","在职");
INSERT INTO employee(user_id,user_name,telephone,mail,user_status) VALUES ("wangfang","王芳","5","wangfang@mail.com","离场");
INSERT INTO employee(user_id,user_name,telephone,mail,user_status) VALUES ("zhangmin","张敏","6","zhangmin@mail.com","临时");
INSERT INTO employee(user_id,user_name,telephone,mail,user_status) VALUES ("zhangwei","张伟","7","zhangwei@mail.com","在职");
INSERT INTO employee(user_id,user_name,telephone,mail,user_status) VALUES ("lijun","李军","8","lijun@mail.com","离场");

select * from employee  where user_name like "王%";

select user_status, count(user_status) from employee group by user_status order by count(user_status) desc;

select employee.user_id,employee.user_name,employee.telephone,employee.mail,employee.user_status 
    from employee,employee_auth,auth 
    where (auth.auth_name = "普通用户" or auth.auth_name = "项目经理")
        and auth.auth_id = employee_auth.auth_id 
        and employee.user_id = employee_auth.user_id;

select employee.user_id,employee.user_name,employee.telephone,employee.mail,employee.user_status 
    from employee left join (employee_auth left join auth on auth.auth_id = employee_auth.auth_id ) on employee.user_id = employee_auth.user_id
    where auth.auth_name = "普通用户" or auth.auth_name = "项目经理";

select employee.user_id,employee.user_name,employee.telephone,employee.mail,employee.user_status,auth.auth_name 
    from employee,employee_auth,auth 
    where (auth.auth_name = "普通用户" or auth.auth_name = "项目经理")
        and auth.auth_id = employee_auth.auth_id 
        and employee.user_id = employee_auth.user_id;

ALTER TABLE employee ADD COLUMN effec_status varchar(50) default "生效";
ALTER TABLE employee DROP COLUMN effec_status;
SELECT * FROM employee;

DELETE FROM auth WHERE auth_id = 4;
SET FOREIGN_KEY_CHECKS=0;
DELETE FROM employee_auth WHERE auth_id = 4;
SET FOREIGN_KEY_CHECKS=1;

将语句的结束符号从分号;临时改为两个$$(可以是自定义)
delimiter $$　　

CREATE PROCEDURE insert_auth ()
    BEGIN
        INSERT INTO auth(auth_name) VALUES ("临时测试1");
        INSERT INTO auth(auth_name) VALUES ("临时测试2");
        INSERT INTO auth(auth_name) VALUES ("临时测试3");
        INSERT INTO auth(auth_name) VALUES ("临时测试4");
        INSERT INTO auth(auth_name) VALUES ("临时测试5");
        INSERT INTO auth(auth_name) VALUES ("临时测试6");
        INSERT INTO auth(auth_name) VALUES ("临时测试7");
        INSERT INTO auth(auth_name) VALUES ("临时测试8");
        INSERT INTO auth(auth_name) VALUES ("临时测试9");
        INSERT INTO auth(auth_name) VALUES ("临时测试10");
    END$$

delimiter ;
call insert_auth();

INSERT INTO employee_auth (user_id, auth_id) VALUES ("lina", 6);
INSERT INTO employee(user_id,user_name,telephone,mail,user_status) VALUES ("lina","李娜","9","lina@mail.com","临时");

select * from employee,auth,employee_auth where auth.auth_id = employee_auth.auth_id and employee.user_id = employee_auth.user_id and employee.user_id = "lina";
DELETE FROM auth WHERE auth_id = 6;
SET FOREIGN_KEY_CHECKS=0;
DELETE FROM employee_auth WHERE auth_id = 6;
SET FOREIGN_KEY_CHECKS=1;
UPDATE employee SET user_status = "离场" WHERE user_id = "lina";

SELECT user_id,user_name,telephone,mail FROM employee WHERE user_status = "离场" OR user_status = "临时";

# 开启事务
BEGIN;
UPDATE employee SET user_status = "离场" WHERE user_id = "zhangmin";
ROLLBACK; COMMIT;

CREATE VIEW status_number AS SELECT user_status,count(user_status) FROM employee GROUP BY user_status ORDER BY count(user_status) DESC;
select * from status_number limit 1;

select employee.user_id,employee.user_name,employee.telephone,employee.mail,employee.user_status,
  GROUP_CONCAT(auth.auth_name) 
  from employee,employee_auth,auth 
    where  auth.auth_id = employee_auth.auth_id 
        and employee.user_id = employee_auth.user_id
        group by employee.user_id order by employee.telephone;


CREATE VIEW all_info AS 
  select employee.user_id,employee.user_name,employee.telephone,employee.mail,employee.user_status,
  GROUP_CONCAT(auth.auth_name) AS auth_name
    from employee,employee_auth,auth 
    where  auth.auth_id = employee_auth.auth_id 
      and employee.user_id = employee_auth.user_id
    group by employee.user_id order by employee.telephone;

select * from all_info;

DROP VIEW IF EXISTS all_info;

select user_name,user_status,auth_name from all_infowhere user_status = "离场";