#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);
  
  TVector<TVector<int> > mV = TMatrix<int>(5);

  TMatrix<int> m1(mV);
  ASSERT_NO_THROW();
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(4);
	m[0][0]=1;
	TMatrix<int>m_copy(m);
	EXPECT_EQ(true,m == m_copy);
  
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix<int> m(4);
  m[0][0]=1;
  TMatrix<int>m_copy(m);
  EXPECT_NE(&m[0][0],&m_copy[0][0]);
}

TEST(TMatrix, can_get_size)
{
  TMatrix<int>m(4);
  EXPECT_EQ(4,m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
  TMatrix<int>m(2);
  m[0][0]=1;
  EXPECT_EQ(1,m[0][0]);
}


TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix<int>m(2);
  ASSERT_ANY_THROW(&m[-1]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix<int>m(2);
  ASSERT_ANY_THROW(&m[10000]);
  
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix<int>m(2);
  ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	const int size = 2;
	TMatrix<int>m1(size);
	TMatrix<int>m2(size);
	for(int i=0;i<size;i++)
	{
		m1[i]=1;
	}
	m2=m1;
	EXPECT_EQ(true, m1 == m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	const int size1 = 2;
	const int size2 = 3;
	TMatrix<int>m1(size1);
	TMatrix<int>m2(size2);
	m2=m1;
	EXPECT_NE(size2,m2.GetSize());
  
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	const int size1 = 2, size2 = 5;
    TMatrix<int> m1(size1), m2(size2);
    for (int i = 0; i < size1; i++)
    {
      m1[i]=11;
    }
    m2 = m1;

    EXPECT_EQ(m1,m2);
  
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  const int size=2;
  TMatrix<int> m1(size);
  TMatrix<int> m2(size);
  EXPECT_EQ(true, m2 == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  const int size = 2;
  TMatrix<int> m1(size);
  EXPECT_EQ(true,m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix<int> m1(3);
  TMatrix<int> m2(4);
  EXPECT_NE(1,m1==m2);
}

  TEST(TMatrix, can_add_matrices_with_equal_size)
  {
	TMatrix<int> m1(4), m2(4);
	m1[1][1] = 4;
	m2[1][1] = 8;
	TMatrix<int> res(m1+m2);
	ASSERT_NO_THROW(res);
	  

 
  }
  

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix<int> m1(4), m2(6);
	m1[1][1] = 4;
	m2[1][1] = 8;
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m1(4), m2(4);
	m1[1][1] = 5;
	m2[1][1] = 6;
	TMatrix<int> res(m1-m2);
	ASSERT_NO_THROW(res);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
   TMatrix<int> m1(4), m2(6);
	m1[1][1] = 4;
	m2[1][1] = 8;
	ASSERT_ANY_THROW(m1 - m2);
}

