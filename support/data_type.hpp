#ifndef __VIVI_DATA_TYPE_HPP__
#define __VIVI_DATA_TYPE_HPP__

/*
 * @brief redis data types.
 */
enum class DataType
{
	NONE = 1,
	STRING = 2,
	LIST = 3,
	SET = 4,
	ZSET = 5,
	HASH = 6,
	STREAM = 7,
};

#endif