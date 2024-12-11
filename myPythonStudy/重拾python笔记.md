# 重拾python笔记(学习来自菜鸟教程)

## `版本`:python 3x

## 一：基本数据类型

#### ** 标记为`*`的为不可变

- Number	 (数字)	* 	---> int float bool complex(复数)
- [String](./type/String.md)            (字符串)      *      --->可视为特殊元组
- bool	     （布尔） ！在python3中，bool类型是int子类 
- [List](./type/List.md)	      （列表）         
- Tuple	   （元组）     *	
- Set		（集合）
- Dictionary   （字典）      有key有value，key不能改变

#### 可通过type()和isinstance()来判断数据类型，区别是：

- type()不会认为子类是一种父类类型。
- isinstance()会认为子类是一种父类类型。


## 二：注释

	- 单行注释：`#`
	- 多行注释: `"""`注释内容`"""`或者 `'''`注释内容`'''`
