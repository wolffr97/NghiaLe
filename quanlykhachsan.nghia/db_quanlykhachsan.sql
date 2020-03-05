-- phpMyAdmin SQL Dump
-- version 4.4.12
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Oct 12, 2017 at 05:45 AM
-- Server version: 5.6.25
-- PHP Version: 5.5.27

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db_quanlykho`
--
CREATE DATABASE IF NOT EXISTS `db_quanlykho` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;
USE `db_quanlykho`;

-- --------------------------------------------------------

--
-- Table structure for table `hotels`
--

CREATE TABLE IF NOT EXISTS `hotels` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `address` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `phone` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `email` varchar(255) COLLATE utf8_unicode_ci DEFAULT NULL,
  `user_id` int(10) unsigned NOT NULL,
  `created_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `updated_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `hotels`
--

INSERT INTO `hotels` (`id`, `name`, `address`, `phone`, `email`, `user_id`, `created_at`, `updated_at`) VALUES
(7, 'Thanh hotel', 'Tan Binh', '3332423', 'thanh@a.com', 0, '2017-06-23 16:36:28', '2017-06-23 16:36:28');

-- --------------------------------------------------------

--
-- Table structure for table `hotel_customers`
--

CREATE TABLE IF NOT EXISTS `hotel_customers` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `gender` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `identifier` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `address` varchar(30) COLLATE utf8_unicode_ci DEFAULT NULL,
  `hotel_room_id` int(10) unsigned NOT NULL,
  `note` varchar(100) COLLATE utf8_unicode_ci DEFAULT NULL,
  `deleted` int(1) NOT NULL DEFAULT '0',
  `created_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `updated_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `hotel_customers`
--

INSERT INTO `hotel_customers` (`id`, `name`, `gender`, `identifier`, `address`, `hotel_room_id`, `note`, `deleted`, `created_at`, `updated_at`) VALUES
(1, 'Le Tran Thai Vu', '1', '22542203', 'TP HCM', 2, '', 0, '2017-07-06 05:50:04', '2017-07-06 05:50:04'),
(2, 'Le Tran Thai Vu', '1', '22542203', 'abcd', 2, '', 0, '2017-07-06 20:15:18', '2017-07-06 20:15:18'),
(3, 'Le Tran Thai Vu', '1', '22542203', 'abcd', 2, '', 0, '2017-07-06 20:15:54', '2017-07-06 20:15:54'),
(4, 'Le Tran Thai Vu', '1', '22542203', 'abcd', 2, '', 0, '2017-07-06 20:16:48', '2017-07-06 20:16:48'),
(5, 'Le Tran Thai Vu', '1', '22542203', '', 2, '', 0, '2017-07-06 20:19:56', '2017-07-06 20:19:56'),
(6, 'Le Tran Thai Vu', '1', '22542203', '', 2, '', 0, '2017-07-06 20:21:16', '2017-07-06 20:21:16'),
(7, 'Le Tran Thai Vu', '1', '22542203', '', 2, '', 0, '2017-07-06 20:24:18', '2017-07-06 20:24:18'),
(8, 'Le Tran Thai Vu', '1', '22542203', 'abcd', 2, '', 0, '2017-07-06 20:25:06', '2017-07-06 20:25:06'),
(9, 'Le Tran Thai Vu', '1', '22542203', '', 2, '', 0, '2017-07-06 20:25:58', '2017-07-06 20:25:58'),
(10, 'Le Tran Thai Vu', '1', '22542203', '', 2, '', 0, '2017-07-06 20:26:29', '2017-07-06 20:26:29'),
(11, 'Le Tran Thai Vu', '1', '22542203', '', 2, '', 0, '2017-07-06 20:27:17', '2017-07-06 20:27:17'),
(12, 'Le Tran Thai Vu', '1', '22542203', '', 2, '', 0, '2017-07-07 03:32:21', '2017-07-07 03:32:21'),
(13, 'Le Tran Thai Vu', '1', '22542203', 'abc', 2, '', 0, '2017-07-07 03:32:39', '2017-07-07 03:32:39'),
(14, 'Le Tran Thai Vu', '1', '22542203', '', 2, '', 0, '2017-07-07 03:33:53', '2017-07-07 03:33:53'),
(15, 'Le Tran Thai Vu', '1', '22542203', 'Cam Ranh', 2, '', 0, '2017-07-07 03:34:57', '2017-07-07 03:34:57'),
(16, 'Le Tran Thai Vu', '1', '22542203', 'Cam Ranh', 2, '', 0, '2017-07-07 03:39:23', '2017-07-07 03:39:23'),
(17, 'Le Tran Thai Vu', '1', '22542203', 'Cam Ranh', 2, '', 0, '2017-07-07 03:40:24', '2017-07-07 03:40:24'),
(18, 'Le Tran Thai Vu', '1', '22542203', '', 2, '', 0, '2017-07-08 11:00:27', '2017-07-08 11:00:27'),
(19, 'Le Tran Thai Vu', '1', '22542203', '', 3, '', 0, '2017-07-11 03:34:21', '2017-07-11 03:34:21'),
(20, 'Le Tran Thai Vu', '1', '22542203', '', 3, '', 0, '2017-07-11 03:35:00', '2017-07-11 03:35:00'),
(21, 'Le Tran Thai Vu', '1', '22542203', 'TP HCM', 4, '', 0, '2017-07-29 08:29:41', '2017-07-29 08:29:41'),
(22, 'Le Tran Thai Vu', '1', '2254223456', '', 2, '', 0, '2017-07-29 10:43:03', '2017-07-29 10:43:03'),
(23, 'Le Tran Thai Vu', '1', '2254223456', '', 2, '', 0, '2017-07-29 10:46:15', '2017-07-29 10:46:15'),
(24, 'Le Tran Thai Vu', '1', '2254223456', '', 2, '', 0, '2017-07-29 10:54:00', '2017-07-29 10:54:00'),
(25, 'Le Tran Thai Vu', '1', '2254223456', '', 2, '', 0, '2017-07-29 11:02:30', '2017-07-29 11:02:30'),
(26, 'Le Tran Thai Vu', '1', '2254223456', '', 2, '', 0, '2017-07-29 11:07:07', '2017-07-29 11:07:07'),
(27, 'CU Thanh', '1', '2254223456', '', 3, '', 0, '2017-07-29 11:27:42', '2017-07-29 11:27:42'),
(28, 'Le Tran Thai Vu', '1', '2254223456', '', 4, '', 0, '2017-07-29 11:31:37', '2017-07-29 11:31:37'),
(29, 'VuLee', '1', '2254223456', '', 3, '', 0, '2017-07-29 11:41:31', '2017-07-29 11:41:31'),
(30, 'Le Tran Thai Vu', '1', '2254223456', '', 3, '', 0, '2017-07-29 11:49:15', '2017-07-29 11:49:15'),
(31, 'Le Tran Thai Vu', '1', '2254223456', '', 3, '', 0, '2017-07-29 12:07:20', '2017-07-29 12:07:20');

-- --------------------------------------------------------

--
-- Table structure for table `hotel_extras`
--

CREATE TABLE IF NOT EXISTS `hotel_extras` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `num` int(10) unsigned NOT NULL,
  `cost` int(10) unsigned NOT NULL,
  `hotel_management_id` int(10) unsigned NOT NULL,
  `deleted` int(1) NOT NULL DEFAULT '0',
  `created_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `updated_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `hotel_extras`
--

INSERT INTO `hotel_extras` (`id`, `name`, `num`, `cost`, `hotel_management_id`, `deleted`, `created_at`, `updated_at`) VALUES
(1, '', 0, 0, 13, 0, '2017-07-08 04:53:59', '2017-07-08 04:53:59'),
(2, 'Nước suối', 1, 20000, 3, 0, '2017-07-08 05:10:41', '2017-07-08 05:10:41'),
(3, 'Coca cola', 1, 40000, 3, 0, '2017-07-08 05:10:41', '2017-07-08 05:10:41'),
(4, '', 0, 0, 1, 0, '2017-07-17 07:49:24', '2017-07-17 07:49:24'),
(5, '', 0, 0, 14, 0, '2017-07-29 10:36:18', '2017-07-29 10:36:18'),
(6, '', 0, 0, 17, 0, '2017-07-29 10:36:53', '2017-07-29 10:36:53'),
(7, '', 0, 0, 16, 0, '2017-07-29 10:41:31', '2017-07-29 10:41:31'),
(8, '', 0, 0, 18, 0, '2017-07-29 10:43:14', '2017-07-29 10:43:14'),
(9, '', 0, 0, 19, 0, '2017-07-29 10:48:41', '2017-07-29 10:48:41'),
(10, '', 0, 0, 20, 0, '2017-07-29 10:59:10', '2017-07-29 10:59:10'),
(11, '', 0, 0, 21, 0, '2017-07-29 11:03:36', '2017-07-29 11:03:36'),
(12, '', 0, 0, 23, 0, '2017-07-29 11:39:42', '2017-07-29 11:39:42'),
(13, '', 0, 0, 23, 0, '2017-07-29 11:41:17', '2017-07-29 11:41:17'),
(14, '', 0, 0, 25, 0, '2017-07-29 11:41:52', '2017-07-29 11:41:52'),
(15, '', 0, 0, 26, 0, '2017-07-29 12:06:57', '2017-07-29 12:06:57'),
(16, '', 0, 0, 27, 0, '2017-07-29 12:15:35', '2017-07-29 12:15:35');

-- --------------------------------------------------------

--
-- Table structure for table `hotel_managements`
--

CREATE TABLE IF NOT EXISTS `hotel_managements` (
  `id` int(10) unsigned NOT NULL,
  `manage_id` int(10) unsigned NOT NULL,
  `hotel_room_id` int(10) unsigned NOT NULL,
  `hotel_customer_id` int(10) unsigned NOT NULL,
  `time_in` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `time_expired` timestamp NULL DEFAULT NULL,
  `time_out` timestamp NULL DEFAULT NULL,
  `status` tinyint(4) NOT NULL DEFAULT '0',
  `cost` int(10) NOT NULL,
  `rent_type` int(1) NOT NULL DEFAULT '0',
  `rent_num` int(10) NOT NULL,
  `note` varchar(100) COLLATE utf8_unicode_ci DEFAULT NULL,
  `deleted` int(1) NOT NULL DEFAULT '0',
  `created_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `updated_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE=InnoDB AUTO_INCREMENT=28 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `hotel_managements`
--

INSERT INTO `hotel_managements` (`id`, `manage_id`, `hotel_room_id`, `hotel_customer_id`, `time_in`, `time_expired`, `time_out`, `status`, `cost`, `rent_type`, `rent_num`, `note`, `deleted`, `created_at`, `updated_at`) VALUES
(19, 1, 2, 23, '2017-07-29 10:46:15', '0000-00-00 00:00:00', '2017-07-29 17:00:00', 1, 0, 0, 0, '', 0, '2017-07-29 10:46:15', '2017-07-29 10:46:15'),
(20, 1, 2, 24, '2017-07-29 10:54:00', '0000-00-00 00:00:00', '2017-07-29 17:00:00', 1, 234000000, 0, 1, '', 0, '2017-07-29 10:54:00', '2017-07-29 10:54:00'),
(21, 1, 2, 25, '2017-07-29 11:02:30', '0000-00-00 00:00:00', '2017-07-29 17:00:00', 1, 0, 0, 0, '', 0, '2017-07-29 11:02:30', '2017-07-29 11:02:30'),
(22, 1, 2, 26, '2017-07-29 11:07:07', '0000-00-00 00:00:00', '2017-07-09 13:00:12', 1, 234000000, 0, 1, '', 0, '2017-07-29 11:07:07', '2017-07-29 11:23:25'),
(23, 1, 3, 27, '2017-07-29 11:27:42', '0000-00-00 00:00:00', '2017-07-29 11:41:12', 1, 234000000, 0, 1, '', 0, '2017-07-29 11:27:42', '2017-07-29 11:41:17'),
(24, 1, 4, 28, '2017-07-29 11:31:37', '0000-00-00 00:00:00', '2017-07-29 11:34:18', 1, 234000000, 0, 1, '', 0, '2017-07-29 11:31:37', '2017-07-29 11:34:18'),
(25, 1, 3, 29, '2017-07-29 11:41:31', '0000-00-00 00:00:00', '2017-07-29 11:41:34', 1, 234000000, 0, 1, '', 0, '2017-07-29 11:41:31', '2017-07-29 11:41:52'),
(26, 1, 3, 30, '2017-07-29 11:49:15', '0000-00-00 00:00:00', '2017-07-29 12:06:52', 1, 234000000, 0, 1, '', 0, '2017-07-29 11:49:15', '2017-07-29 12:06:57'),
(27, 1, 3, 31, '2017-07-29 12:07:20', '0000-00-00 00:00:00', '2017-07-29 12:15:31', 1, 200000, 1, 1, '', 0, '2017-07-29 12:07:20', '2017-07-29 12:15:35');

-- --------------------------------------------------------

--
-- Table structure for table `hotel_prices`
--

CREATE TABLE IF NOT EXISTS `hotel_prices` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(100) COLLATE utf8_unicode_ci DEFAULT NULL,
  `price_day` int(10) unsigned NOT NULL,
  `price_hour` int(10) unsigned NOT NULL,
  `price_hour_next` int(10) unsigned NOT NULL,
  `deleted` int(1) NOT NULL DEFAULT '0',
  `created_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `updated_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `hotel_prices`
--

INSERT INTO `hotel_prices` (`id`, `name`, `price_day`, `price_hour`, `price_hour_next`, `deleted`, `created_at`, `updated_at`) VALUES
(1, 'giá cũ', 234000000, 200000, 500000, 0, '2017-06-30 03:15:01', '2017-07-29 10:20:49');

-- --------------------------------------------------------

--
-- Table structure for table `hotel_rooms`
--

CREATE TABLE IF NOT EXISTS `hotel_rooms` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(30) COLLATE utf8_unicode_ci NOT NULL,
  `manage_id` int(10) unsigned NOT NULL,
  `hotel_price_id` int(10) unsigned NOT NULL,
  `status` int(1) NOT NULL DEFAULT '0',
  `deleted` int(1) NOT NULL DEFAULT '0',
  `created_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `updated_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `hotel_rooms`
--

INSERT INTO `hotel_rooms` (`id`, `name`, `manage_id`, `hotel_price_id`, `status`, `deleted`, `created_at`, `updated_at`) VALUES
(2, 'Phong 1', 1, 1, 1, 0, '2017-06-30 02:54:42', '2017-06-30 02:55:27'),
(3, 'Phòng B', 1, 1, 0, 0, '0000-00-00 00:00:00', '0000-00-00 00:00:00'),
(4, 'Phòng Cfd', 1, 1, 1, 0, '0000-00-00 00:00:00', '2017-07-08 13:01:16'),
(6, 'Le Tran Thai Vu', 0, 0, 0, 0, '2017-07-09 09:33:16', '2017-07-09 09:33:16'),
(7, 'Lesson 1', 0, 0, 0, 0, '2017-07-09 10:05:05', '2017-07-09 10:05:05'),
(8, 'Phuong Nam HotelV', 0, 0, 0, 0, '2017-07-09 10:05:22', '2017-07-28 07:39:06'),
(9, 'Phòng thường', 0, 0, 0, 0, '2017-07-28 07:30:10', '2017-07-28 07:30:10');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(10) unsigned NOT NULL,
  `name` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `email` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `password` varchar(60) COLLATE utf8_unicode_ci NOT NULL,
  `remember_token` varchar(100) COLLATE utf8_unicode_ci DEFAULT NULL,
  `role_id` int(11) unsigned NOT NULL,
  `manage_id` int(10) DEFAULT NULL,
  `manage_type_id` int(11) DEFAULT NULL,
  `created_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `updated_at` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `name`, `email`, `password`, `remember_token`, `role_id`, `manage_id`, `manage_type_id`, `created_at`, `updated_at`) VALUES
(1, 'thanh', 'thanh@a.com', '$2y$10$yJtI5vA.ZFXKWuXZyzgFsOiD7ibwA.cdG0k5phPcLFZpux4XVLczu', 'Q5mKh7bvk8UWCCQTBcIKH413kSLXFZVIrQdAFtEQ', 2, NULL, 1, '2017-06-26 23:27:35', '2017-06-26 23:27:35'),
(3, 'Hoàng Nam - Thủ kho', 'admin@gmail.com', '$2y$10$7LuqenZX8EI2OhVEt4yK.O7q7A.M5F7Co3j6oATlK8zGHGgOqjfLC', 'rmbXjSodxg49M0lhMYcyWel1YYjcOg6QykKYN6HqPp4L6BOoNyH4ig0goseO', 1, NULL, NULL, '2016-07-03 15:14:22', '2017-07-20 12:29:25'),
(6, 'user11', 'admin@gmail.com11', '$2y$10$ZAqtgJkDB.DcbprcEq/.COg6tHLMJevrTsQmUrUo2uqGr4hpb7z02', 'YmPaD0kywRMWWBP18UQF5YcY5ksNnQom1xfzE6jm', 2, NULL, 1, '2017-06-30 02:39:51', '2017-06-30 02:39:51');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `hotel_customers`
--
ALTER TABLE `hotel_customers`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `hotel_extras`
--
ALTER TABLE `hotel_extras`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `hotel_managements`
--
ALTER TABLE `hotel_managements`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `hotel_prices`
--
ALTER TABLE `hotel_prices`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `hotel_rooms`
--
ALTER TABLE `hotel_rooms`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD KEY `nguoidung_id` (`role_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `hotel_customers`
--
ALTER TABLE `hotel_customers`
  MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=32;
--
-- AUTO_INCREMENT for table `hotel_extras`
--
ALTER TABLE `hotel_extras`
  MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=17;
--
-- AUTO_INCREMENT for table `hotel_managements`
--
ALTER TABLE `hotel_managements`
  MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=28;
--
-- AUTO_INCREMENT for table `hotel_prices`
--
ALTER TABLE `hotel_prices`
  MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=2;
--
-- AUTO_INCREMENT for table `hotel_rooms`
--
ALTER TABLE `hotel_rooms`
  MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=10;
--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(10) unsigned NOT NULL AUTO_INCREMENT,AUTO_INCREMENT=7;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
