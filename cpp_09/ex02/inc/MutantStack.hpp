/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:01:20 by daeunki2          #+#    #+#             */
/*   Updated: 2025/10/06 16:39:39 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // 기본 생성자, 복사 생성자, 대입 연산자, 소멸자
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack<T>& src) : std::stack<T>(src) {}
    MutantStack<T>& operator=(const MutantStack<T>& src) {
        if (this != &src)
            std::stack<T>::operator=(src);
        return *this;
    }
    ~MutantStack() {}

    // 타입 정의
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    // begin()과 end()를 정의하여 내부 컨테이너에 대한 접근을 허용
    iterator begin() {
        return this->c.begin();  // stack의 내부 컨테이너 접근
    }

    iterator end() {
        return this->c.end();  // stack의 내부 컨테이너 접근
    }

    const_iterator cbegin() const {
        return this->c.cbegin();  // const 접근
    }

    const_iterator cend() const {
        return this->c.cend();  // const 접근
    }
};