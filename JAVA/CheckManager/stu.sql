/*
 Navicat Premium Data Transfer

 Source Server         : cy
 Source Server Type    : MySQL
 Source Server Version : 80019
 Source Host           : localhost:3306
 Source Schema         : stu

 Target Server Type    : MySQL
 Target Server Version : 80019
 File Encoding         : 65001

 Date: 30/11/2020 23:39:14
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for Course
-- ----------------------------
DROP TABLE IF EXISTS `Course`;
CREATE TABLE `Course` (
  `Cno` int NOT NULL,
  `Cname` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `Ctime` varchar(255) DEFAULT NULL,
  `Ccredit` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`Cno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of Course
-- ----------------------------
BEGIN;
INSERT INTO `Course` VALUES (1, '数学分析', '100', '6');
INSERT INTO `Course` VALUES (2, '普通物理', '110', '6');
INSERT INTO `Course` VALUES (3, '微机原理', '80', '4');
INSERT INTO `Course` VALUES (4, '数据结构', '72', '4');
INSERT INTO `Course` VALUES (5, '操作系统', '80', '5');
INSERT INTO `Course` VALUES (6, '数据库原理', '80', '4');
INSERT INTO `Course` VALUES (7, '编译原理', '60', '3');
INSERT INTO `Course` VALUES (8, '程序设计', '40', '2');
COMMIT;

-- ----------------------------
-- Table structure for S1
-- ----------------------------
DROP TABLE IF EXISTS `S1`;
CREATE TABLE `S1` (
  `SNO` varchar(10) NOT NULL COMMENT '学号',
  `SNAME` varchar(20) DEFAULT NULL COMMENT '姓名',
  `SD` varchar(50) DEFAULT NULL COMMENT '系别',
  `SA` int(4) unsigned zerofill DEFAULT NULL COMMENT '年龄',
  PRIMARY KEY (`SNO`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of S1
-- ----------------------------
BEGIN;
INSERT INTO `S1` VALUES ('96001', '马小燕', 'CS', 0021);
INSERT INTO `S1` VALUES ('96002', '黎明', 'CS', 0018);
INSERT INTO `S1` VALUES ('96005', '司马志明', 'CS', 0018);
INSERT INTO `S1` VALUES ('97002', '李成功', 'CS', 0020);
INSERT INTO `S1` VALUES ('97004', '李丽', 'CS', 0019);
COMMIT;

-- ----------------------------
-- Table structure for Score
-- ----------------------------
DROP TABLE IF EXISTS `Score`;
CREATE TABLE `Score` (
  `Sno` int NOT NULL,
  `Cno` int NOT NULL,
  `Grade` varchar(255) DEFAULT NULL,
  KEY `SNO-S` (`Sno`),
  KEY `CNO-S` (`Cno`),
  CONSTRAINT `CNO-S` FOREIGN KEY (`Cno`) REFERENCES `Course` (`Cno`),
  CONSTRAINT `SNO-S` FOREIGN KEY (`Sno`) REFERENCES `Student` (`Sno`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of Score
-- ----------------------------
BEGIN;
INSERT INTO `Score` VALUES (96001, 1, '77');
INSERT INTO `Score` VALUES (96001, 3, '89');
INSERT INTO `Score` VALUES (96001, 4, '86');
INSERT INTO `Score` VALUES (96001, 5, '82');
INSERT INTO `Score` VALUES (96002, 1, '88');
INSERT INTO `Score` VALUES (96002, 3, '92');
INSERT INTO `Score` VALUES (96002, 6, '90');
INSERT INTO `Score` VALUES (96003, 1, '69');
INSERT INTO `Score` VALUES (96003, 3, '91');
INSERT INTO `Score` VALUES (96004, 1, '87');
INSERT INTO `Score` VALUES (96005, 4, '92');
INSERT INTO `Score` VALUES (96005, 5, '90');
INSERT INTO `Score` VALUES (96005, 6, '89');
INSERT INTO `Score` VALUES (96005, 7, '76');
INSERT INTO `Score` VALUES (97001, 1, '96');
INSERT INTO `Score` VALUES (97001, 8, '95');
INSERT INTO `Score` VALUES (97002, 3, '91');
INSERT INTO `Score` VALUES (97002, 4, NULL);
INSERT INTO `Score` VALUES (97002, 6, '92');
INSERT INTO `Score` VALUES (97004, 5, '90');
INSERT INTO `Score` VALUES (97004, 6, '85');
COMMIT;

-- ----------------------------
-- Table structure for Student
-- ----------------------------
DROP TABLE IF EXISTS `Student`;
CREATE TABLE `Student` (
  `Sno` int NOT NULL AUTO_INCREMENT,
  `Sname` varchar(255) NOT NULL,
  `Ssex` varchar(255) NOT NULL,
  `Sage` varchar(255) DEFAULT NULL,
  `Sdept` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`Sno`)
) ENGINE=InnoDB AUTO_INCREMENT=97005 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of Student
-- ----------------------------
BEGIN;
INSERT INTO `Student` VALUES (96001, '马小燕', '女', '21', 'CS');
INSERT INTO `Student` VALUES (96002, '黎明', '男', '18', 'CS');
INSERT INTO `Student` VALUES (96003, '刘东明', '男', '18', 'MA');
INSERT INTO `Student` VALUES (96004, '赵志勇', '男', '20', 'IS');
INSERT INTO `Student` VALUES (96005, '司马志明', '', '18', 'CS');
INSERT INTO `Student` VALUES (97001, '马蓉', '女', '19', 'MA');
INSERT INTO `Student` VALUES (97002, '李成功', '男', '20', 'CS');
INSERT INTO `Student` VALUES (97003, '黎明', '女', '19', 'IS');
INSERT INTO `Student` VALUES (97004, '李丽', '女', '19', 'CS');
COMMIT;

-- ----------------------------
-- Table structure for Teacher
-- ----------------------------
DROP TABLE IF EXISTS `Teacher`;
CREATE TABLE `Teacher` (
  `Tno` int NOT NULL,
  `Tname` varchar(255) NOT NULL,
  `Tsex` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `Cno` int DEFAULT NULL,
  `Tdept` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`Tno`),
  KEY `CNO-T` (`Cno`),
  CONSTRAINT `CNO-T` FOREIGN KEY (`Cno`) REFERENCES `Course` (`Cno`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- ----------------------------
-- Records of Teacher
-- ----------------------------
BEGIN;
INSERT INTO `Teacher` VALUES (1101, '王成刚', '男', 4, '   CS ');
INSERT INTO `Teacher` VALUES (1102, '李正科', '男', 3, '   CS');
INSERT INTO `Teacher` VALUES (1103, '严敏', '女', 1, '   MA');
INSERT INTO `Teacher` VALUES (1105, '王成银', '女', 4, '   IS');
INSERT INTO `Teacher` VALUES (1106, '李副科', '女', 3, '   MA ');
INSERT INTO `Teacher` VALUES (1107, '刘玉兰', '女', 6, '   CS');
INSERT INTO `Teacher` VALUES (1108, '王成铁', '男', 4, '   IS');
INSERT INTO `Teacher` VALUES (1109, '马兰', '女', 8, '   CS');
COMMIT;

-- ----------------------------
-- View structure for v_student_cs
-- ----------------------------
DROP VIEW IF EXISTS `v_student_cs`;
CREATE ALGORITHM = UNDEFINED SQL SECURITY DEFINER VIEW `v_student_cs` AS select `s`.`Sno` AS `SNO`,`s`.`Sname` AS `SNAME`,`s`.`Ssex` AS `SSEX`,`s`.`Sdept` AS `SDEPT`,`s`.`Sage` AS `SAGE`,`c`.`Grade` AS `GRADE` from (`student` `s` join `score` `c`) where (`s`.`Sno` = `c`.`Sno`);

-- ----------------------------
-- Procedure structure for getinfo
-- ----------------------------
DROP PROCEDURE IF EXISTS `getinfo`;
delimiter ;;
CREATE PROCEDURE `stu`.`getinfo`(in low INT, in high INT)
BEGIN
 SELECT
  Sname,
  Sdept,
  Grade 
 FROM
  Student,
  Course,
  Score 
 WHERE
  ( Course.Cname = '数据结构' ) 
  AND ( Student.Sno = Score.Sno ) 
  AND ( Course.Cno = Score.Cno ) 
  AND ( Score.Grade > low ) 
 AND ( Score.Grade < high ) ;
 END
;;
delimiter ;

SET FOREIGN_KEY_CHECKS = 1;
