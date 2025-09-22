/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 22:48:45 by daeunki2          #+#    #+#             */
/*   Updated: 2025/09/21 23:03:15 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#include <exception>

// int 타입의 Array 테스트
void testIntArray() {
    std::cout << "--- Testing Array<int> ---" << std::endl;

    // 1. 기본 생성자 및 getSize 테스트
    Array<int> emptyArray;
    std::cout << "1. Empty array size: " << emptyArray.getSize() << std::endl;

    // 2. 파라미터 있는 생성자 테스트
    Array<int> intArray(5);
    std::cout << "2. Array of size 5 created." << std::endl;
    std::cout << "   Current size: " << intArray.getSize() << std::endl;

    // 3. 서브스크립트 연산자 및 값 할당 테스트
    std::cout << "3. Assigning values to intArray:" << std::endl;
    for (unsigned int i = 0; i < intArray.getSize(); ++i) {
        intArray[i] = (i + 1) * 10;
        std::cout << "   intArray[" << i << "] = " << intArray[i] << std::endl;
    }

    // 4. 복사 생성자 테스트
    Array<int> copyArray(intArray);
    std::cout << "4. Copied intArray to copyArray." << std::endl;
    std::cout << "   copyArray[2]: " << copyArray[2] << std::endl;

    // 5. 복사본 수정이 원본에 영향 없는지 테스트
    copyArray[2] = 99;
    std::cout << "5. Modified copyArray[2] to 99." << std::endl;
    std::cout << "   copyArray[2] is now: " << copyArray[2] << std::endl;
    std::cout << "   Original intArray[2] remains: " << intArray[2] << std::endl;

    // 6. 대입 연산자 테스트
    Array<int> assignedArray;
    assignedArray = intArray;
    std::cout << "6. Assigned intArray to assignedArray." << std::endl;
    std::cout << "   assignedArray[4]: " << assignedArray[4] << std::endl;
    assignedArray[4] = 77;
    std::cout << "7. Modified assignedArray[4] to 77." << std::endl;
    std::cout << "   assignedArray[4] is now: " << assignedArray[4] << std::endl;
    std::cout << "   Original intArray[4] remains: " << intArray[4] << std::endl;

    // 8. 예외 처리 테스트
    std::cout << "8. Testing exception for out-of-bounds access:" << std::endl;
    try {
        std::cout << "   Trying to access intArray[10]..." << std::endl;
        intArray[10] = 0;
    } catch (const std::exception& e) {
        std::cerr << "   Caught exception: " << e.what() << std::endl;
    }

    std::cout << "--- Test for Array<int> finished ---" << std::endl << std::endl;
}

// double 타입의 Array 테스트
void testDoubleArray() {
    std::cout << "--- Testing Array<double> ---" << std::endl;
    Array<double> doubleArray(3);
    for (unsigned int i = 0; i < doubleArray.getSize(); ++i) {
        doubleArray[i] = 1.1 * (i + 1);
        std::cout << "   doubleArray[" << i << "] = " << doubleArray[i] << std::endl;
    }
    std::cout << "--- Test for Array<double> finished ---" << std::endl << std::endl;
}

int main() {
    testIntArray();
    testDoubleArray();

    return 0;
}