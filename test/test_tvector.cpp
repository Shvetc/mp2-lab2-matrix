#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> v(5);
  v[0]=1;

  TVector<int> v_copy(v);
  EXPECT_EQ(true, v == v_copy);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(5);
  v[0]=1;
  TVector<int> v_copy(v);
  
  EXPECT_NE(&v[0], &v_copy[0]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
   TVector<int> v(4);

   ASSERT_ANY_THROW(&v[-1]);	
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
   TVector<int> v(4);
   ASSERT_ANY_THROW(&v[100]);  
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(4);

	ASSERT_NO_THROW(v = v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	const int size=2;
	TVector<int> v1(size);
	TVector<int> v2(size);
	for (int i=0;i<size;i++)
	{
		v1[i]=1;
	}
	v2=v1;
	EXPECT_EQ(true, v1 == v2);
}

TEST(TVector, assign_operator_change_vector_size)
{
  const int size1 = 2, size2 = 5;
  TVector<int> v1(size1), v2(size2);
  v2 = v1;

  EXPECT_NE(size2, v2.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  const int size1 = 2, size2 = 5;
  TVector<int> v1(size1), v2(size2);
  for (int i = 0; i < size1; i++)
  {
    v1[i]=i;
  }
  v2 = v1;

  EXPECT_EQ(true, v2 == v1);
  
}

TEST(TVector, compare_equal_vectors_return_true)
{
	const int size=2;
	TVector<int> v1(size);
	TVector<int> v2(v1);
	EXPECT_EQ(true, v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	const int size=2;
	TVector<int> v1(size);
	EXPECT_EQ(true, v1 == v1);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(2);
	TVector<int> v2(1);
	EXPECT_NE(1,v1==v2);
}

TEST(TVector, can_add_scalar_to_vector)
{
  int add=2;
  int size = 2;
  TVector<int> v1(size);
  for(int i = 0; i < size; i++)
  {
	  v1[i]=0;
  }
  TVector<int> v2(size);
  for(int i = 0; i < size; i++)
  {
	  v2[i]=0;
  }
  v2 = v1 + add;
  EXPECT_EQ(add,v2[0]);
  EXPECT_EQ(add,v2[1]);// «начение вектора после прибавлени€ скал€ра
  EXPECT_EQ(0,v1[0]); /// ѕроверка значени€ вектора до прибавлени€ скал€ра
}
 

TEST(TVector, can_subtract_scalar_from_vector)
{
  int diff = 2;
  int size = 2;
  TVector<int> v1(size);
  for(int i = 0; i < size; i++)
  {
	  v1[i]=0;
  }
  TVector<int> v2(size);
  for(int i = 0; i < size; i++)
  {
	  v2[i]=0;
  }
  v2 = v1 - diff;
  EXPECT_EQ(-diff,v2[0]);
  EXPECT_EQ(-diff,v2[1]);
  EXPECT_EQ(0,v1[0]); /// ѕроверка значени€ вектора до вычитани€ скал€ра
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  int mult = 2;
  int size = 2;
  TVector<int> v1(size);
  for(int i = 0; i < size; i++)
  {
	  v1[i] = 1;
  }
  TVector<int> v2(size);
  for(int i = 0; i < size; i++)
  {
	  v2[i] = 1;
  }
  v2=v1*mult;
  EXPECT_EQ(mult,v2[0]);
  EXPECT_EQ(mult,v2[1]);
  EXPECT_EQ(1,v1[0]); /// ѕроверка значени€ вектора до умножени€  скал€ра

}

TEST(TVector, can_add_vectors_with_equal_size)
{
  int size1 = 2;
  int size2 = 2;
  TVector<int> v1(size1);
  for(int i = 0; i < size1; i++)
  {
	  v1[i] = 0;
  }
  TVector<int> v2(size2);
  for(int i = 0; i < size2; i++)
  {
	  v2[i] = 1;
  }
  TVector<int> summ(v1+v2);
  
  EXPECT_EQ(v1[0] + v2[0], summ[0]);
  EXPECT_EQ(v1[1] + v2[1], summ[1]);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{  
  int size1 = 2;
  int size2 = 3;
  TVector<int> v1(size1);
  TVector<int> v2(size2);
  EXPECT_EQ(true,v1!=v2);
  ASSERT_ANY_THROW(v1+v2);

}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  int size1 = 2;
  int size2 = 2;
  TVector<int> v1(size1);
  for(int i = 0; i < size1; i++)
  {
	  v1[i] = 0;
  }
  TVector<int> v2(size2);
  for(int i = 0; i < size2; i++)
  {
	  v2[i] = 1;
  }
  TVector<int> sub(v1-v2);
 // std::cout<<sub(v1-v2)<<endl;
  EXPECT_EQ(v1[0] - v2[0], sub[0]);
  EXPECT_EQ(v1[1] - v2[1], sub[1]);
  
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  int size1 = 2;
  int size2 = 3;
  TVector<int> v1(size1);
  TVector<int> v2(size2);
  EXPECT_EQ(true,v1!=v2);
  ASSERT_ANY_THROW(v1-v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  int size1 = 2;
  int size2 = 2;
  TVector<int> v1(size1);
  for(int i = 0; i < size1; i++)
  {
	  v1[i] = 1;
  }
  TVector<int> v2(size2);
  for(int i = 0; i < size2; i++)
  {
	  v2[i] = 1;
  }
  int expected = 2;
  int multres = v1*v2;
  
 // std::cout<<sub(v1-v2)<<endl;
  EXPECT_EQ(expected, multres);
  
  
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  int size1 = 2;
  int size2 = 3;
  TVector<int> v1(size1);
  TVector<int> v2(size2);
  EXPECT_EQ(true,v1!=v2);
  ASSERT_ANY_THROW(v1*v2);
  
}

