-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 22, 2021 at 06:26 AM
-- Server version: 10.4.17-MariaDB
-- PHP Version: 7.4.13

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `workshopzairi`
--

-- --------------------------------------------------------

--
-- Table structure for table `admin`
--

CREATE TABLE `admin` (
  `AdminID` int(11) NOT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Password` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `admin`
--

INSERT INTO `admin` (`AdminID`, `Name`, `Password`) VALUES
(1, 'zairy', '123'),
(2, 'atiqah', '456');

-- --------------------------------------------------------

--
-- Table structure for table `report`
--

CREATE TABLE `report` (
  `StockID` int(11) NOT NULL,
  `StaffID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `StaffID` int(11) NOT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `IC` varchar(255) DEFAULT NULL,
  `Gender` char(1) DEFAULT NULL,
  `Age` varchar(255) DEFAULT NULL,
  `Address` varchar(255) DEFAULT NULL,
  `Phone` varchar(255) DEFAULT NULL,
  `Category` varchar(255) DEFAULT NULL,
  `Salary` decimal(8,2) DEFAULT NULL,
  `Password` varchar(255) DEFAULT NULL,
  `AdminID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`StaffID`, `Name`, `IC`, `Gender`, `Age`, `Address`, `Phone`, `Category`, `Salary`, `Password`, `AdminID`) VALUES
(1, 'Abd Meon', '670711015421', 'M', '53', 'NO 36 KAMPUNG TRIANG TENGAH', '0195356779', 'FULL-TIME', '1000.00', '123', 1),
(2, 'Nasitah', '670815015820', 'F', '44', 'NO 36 KAMPUNG TRIANG TENGAH', '01136112166', 'PART-TIME', '1100.00', '123', 1),
(3, 'Irfan Meon', '020225011077', 'M', '18', 'N0 18,JALAN LAUT 3', '0123456789', 'PART-TIME', '1000.00', '654', 1),
(5, 'Fatimah', '990912011099', 'F', '21', '19,JALAN BERLUKAR JULING', '0198765432', 'PART-TIME', '1000.00', '123', 2),
(7, 'Fadzli', '780910015677', 'M', '34', 'No 9 ,Jalan Tepi Pantai', '01912345678', 'FULL-TIME', '1000.00', '654', 2),
(9, 'Aqilah Subari', '030909011078', 'F', '18', 'NO T44,JALAN WAYANG TIGA', '0198765432', 'PART-TIME', '1100.00', 'aq03', 1),
(11, 'Anis', '010909015420', 'F', '19', 'Jalan Laut Tiga', '0198765432', 'PART-TIME', '1000.00', '876', 1),
(14, 'Abd Zakari', '000803011057', 'M', '21', 'No 36 kampung triang tengah', '0198765432', 'FULL-TIME', '1000.00', '123', 1);

-- --------------------------------------------------------

--
-- Table structure for table `stock_in_shop`
--

CREATE TABLE `stock_in_shop` (
  `StockID` int(11) NOT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Quantity` int(11) DEFAULT NULL,
  `Stock_Price` decimal(8,2) DEFAULT NULL,
  `Selling_Price` decimal(8,2) DEFAULT NULL,
  `Category` varchar(255) DEFAULT NULL,
  `Exp_Date` date DEFAULT NULL,
  `Value` decimal(8,2) DEFAULT NULL,
  `Profit` decimal(8,2) DEFAULT NULL,
  `AdminID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `stock_in_shop`
--

INSERT INTO `stock_in_shop` (`StockID`, `Name`, `Quantity`, `Stock_Price`, `Selling_Price`, `Category`, `Exp_Date`, `Value`, `Profit`, `AdminID`) VALUES
(1, 'SUGAR PRAI 1KG', 50, '3.00', '3.20', 'NON-PERISHABLE', '2020-11-19', '160.00', '122.00', 1),
(2, 'HIMALAYA ROCK SALT 400G', 50, '3.00', '3.50', 'NON-PERISHABLE', '2020-11-19', '175.00', '100.00', 1),
(4, 'EGG GRED A', 30, '0.40', '0.50', 'PERISHABLE', '2021-01-09', '15.00', '2.00', 1),
(6, 'MEAT', 20, '10.20', '10.70', 'PERISHABLE', '2021-05-18', '214.00', '100.00', 1),
(7, '100 PLUS', 30, '1.50', '1.70', 'NON-PERISHABLE', '2020-04-12', '51.00', '10.00', 1),
(8, 'COCA-COLA', 40, '1.50', '1.70', 'NON-PERISHABLE', '2021-04-12', '68.00', '22.00', 1),
(9, 'BESTARI COOKING OIL', 20, '2.80', '3.00', 'NON-PERISHABLE', '2021-11-19', '60.00', '5.00', 2),
(10, 'MOUNTAIN DEW', 20, '1.60', '1.80', 'NON-PERISHABLE', '2021-01-09', '36.00', '9.00', 2),
(11, 'WHEAT FLOUR 1KG', 60, '2.10', '2.50', 'NON-PERISHABLE', '2021-01-12', '150.00', '5.50', 1),
(13, 'KURMA MILK ', 35, '7.50', '8.00', 'PERISHABLE', '2020-12-30', '280.00', '10.00', 2),
(14, 'MARKER', 30, '2.10', '2.30', 'STATIONERY', '2020-12-12', '69.00', '20.00', 1),
(15, 'MECHANICAL PENSIL', 50, '1.20', '1.50', 'STATIONERY', '2020-12-12', '75.00', '10.00', 2),
(16, 'ERASER', 30, '0.10', '0.20', 'STATIONERY', '2020-12-30', '6.00', '30.00', NULL),
(17, 'MILO 400G', 30, '5.20', '5.50', 'NON-PERISHABLE', '2020-12-31', '165.00', '30.00', 1),
(18, 'MILO 1KG', 20, '18.00', '18.50', 'NON-PERISHABLE', '2020-12-31', '370.00', '30.00', 1),
(19, 'MILO 800G', 10, '10.50', '11.00', 'NON-PERISHABLE ', '2020-12-31', '110.00', '20.00', 1),
(20, 'CORN FLOUR 400G', 10, '1.50', '1.70', 'NON-PERISHABLE', '2020-12-12', '17.00', '10.00', 1),
(21, 'EGG GRED B', 40, '0.30', '0.40', 'PERISHABLE', '2021-01-09', '16.00', '1.00', 1),
(25, 'EGG GRED C', 40, '0.20', '0.30', 'PERISHABLE', '2021-01-09', '12.00', '1.00', NULL),
(26, 'GULA PRAI 2KG', 30, '5.50', '6.00', 'NON-PERISHABLE', '2020-12-31', '180.00', '10.00', 1),
(28, 'COLOURING BOOK', 20, '1.00', '1.20', 'STATIONERY', '2021-02-12', '24.00', '0.00', 1),
(29, 'TAUHU KERING ', 40, '2.00', '2.20', 'NON-PERISHABLE', '2021-02-01', '88.00', '0.00', 1);

-- --------------------------------------------------------

--
-- Table structure for table `stock_in_store`
--

CREATE TABLE `stock_in_store` (
  `StockID` int(11) NOT NULL,
  `Name` varchar(255) DEFAULT NULL,
  `Quantity` int(11) DEFAULT NULL,
  `Stock_Price` decimal(8,2) DEFAULT NULL,
  `Selling_Price` decimal(8,2) DEFAULT NULL,
  `Category` varchar(255) DEFAULT NULL,
  `Exp_Date` date DEFAULT NULL,
  `Value` decimal(8,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `stock_in_store`
--

INSERT INTO `stock_in_store` (`StockID`, `Name`, `Quantity`, `Stock_Price`, `Selling_Price`, `Category`, `Exp_Date`, `Value`) VALUES
(1, 'SUGAR PRAI 1KG', 100, '3.00', '3.20', 'NON-PERISHABLE', '2020-11-19', '320.00'),
(2, 'HIMALAYA ROCK SALT 400G', 100, '3.00', '3.50', 'NON-PERISHABLE', '2020-11-19', '350.00'),
(4, 'EGG GRED A', 30, '0.40', '0.50', 'PERISHABLE', '2021-01-09', '15.00'),
(6, 'MEAT', 29, '10.20', '10.70', 'PERISHABLE', '2021-05-19', '310.30'),
(7, '100 PLUS', 20, '1.50', '1.70', 'NON-PERISHABLE', '2021-04-12', '34.00'),
(8, 'COCA-COLA', 10, '1.50', '1.70', 'NON-PERISHABLE', '2021-04-12', '17.00'),
(9, 'OIL', 10, '2.80', '3.00', 'NON-PERISHABLE', '2020-11-19', '30.00'),
(13, 'KURMA MILK', 50, '7.50', '8.00', 'PERISHABLE', '2020-12-13', '400.00'),
(14, 'MARKER', 30, '2.10', '2.30', 'STATIONERY', '2020-12-12', '69.00'),
(16, 'ERASER', 15, '0.10', '0.20', 'STATIONERY', '2020-12-30', '3.00'),
(20, 'CORN FLOUR', 10, '1.50', '1.70', 'NON-PERISHABLE', '2020-12-12', '17.00');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admin`
--
ALTER TABLE `admin`
  ADD PRIMARY KEY (`AdminID`);

--
-- Indexes for table `report`
--
ALTER TABLE `report`
  ADD PRIMARY KEY (`StockID`,`StaffID`),
  ADD KEY `StaffID` (`StaffID`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`StaffID`),
  ADD KEY `AdminID` (`AdminID`);

--
-- Indexes for table `stock_in_shop`
--
ALTER TABLE `stock_in_shop`
  ADD PRIMARY KEY (`StockID`),
  ADD KEY `AdminID` (`AdminID`);

--
-- Indexes for table `stock_in_store`
--
ALTER TABLE `stock_in_store`
  ADD PRIMARY KEY (`StockID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `admin`
--
ALTER TABLE `admin`
  MODIFY `AdminID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `staff`
--
ALTER TABLE `staff`
  MODIFY `StaffID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=15;

--
-- AUTO_INCREMENT for table `stock_in_shop`
--
ALTER TABLE `stock_in_shop`
  MODIFY `StockID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=32;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `report`
--
ALTER TABLE `report`
  ADD CONSTRAINT `report_ibfk_1` FOREIGN KEY (`StockID`) REFERENCES `stock_in_shop` (`StockID`),
  ADD CONSTRAINT `report_ibfk_2` FOREIGN KEY (`StockID`) REFERENCES `stock_in_store` (`StockID`),
  ADD CONSTRAINT `report_ibfk_3` FOREIGN KEY (`StaffID`) REFERENCES `staff` (`StaffID`);

--
-- Constraints for table `staff`
--
ALTER TABLE `staff`
  ADD CONSTRAINT `staff_ibfk_1` FOREIGN KEY (`AdminID`) REFERENCES `admin` (`AdminID`);

--
-- Constraints for table `stock_in_shop`
--
ALTER TABLE `stock_in_shop`
  ADD CONSTRAINT `stock_in_shop_ibfk_1` FOREIGN KEY (`AdminID`) REFERENCES `admin` (`AdminID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
