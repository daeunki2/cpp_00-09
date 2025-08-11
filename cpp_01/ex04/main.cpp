/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:13:38 by daeunki2          #+#    #+#             */
/*   Updated: 2025/08/11 22:05:59 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>
/*
다음 순서로 세 개의 인자를 받는 프로그램을 작성하세요: 파일 이름과 두 개의 문자열 s1, s2.
프로그램은 <filename> 파일을 열고 그 내용을 <filename>.replace 라는 새 파일에 복사하는데, 이 과정에서 s1의 모든 등장 부분을 s2로 바꿔야 합니다.
C 파일 조작 함수 사용은 금지되며, 이를 사용하면 부정행위로 간주됩니다.
std::string 클래스의 모든 멤버 함수는 사용할 수 있지만, replace 함수는 사용할 수 없습니다. 현명하게 사용하세요!
물론, 예상치 못한 입력과 오류 상황도 처리해야 합니다.
프로그램이 정상 작동하는지 확인하기 위해 자신의 테스트도 만들어 제출해야 합니다.
*/
int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string filename = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];

        std::ifstream inputFile(filename);
        if (!inputFile.is_open())
        {
            std::cerr << "Error: Cannot open file " << filename << std::endl;
            return 1;
        }
        if (s1.empty() || s2.empty())
        {
            std::cerr << "Error: Strings to find and replace must not be empty." << std::endl;
            return 1;
        }

        // 여기서부터 파일 읽기, 치환, 새 파일 생성 등 시작

        // ...

        inputFile.close();
    }
    else
    {
        std::cout << "Usage : ./program filename string1 string2" << std::endl;
        return 1;
    }
    
    return 0;
}