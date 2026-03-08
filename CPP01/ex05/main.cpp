/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuknapek <zuknapek@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:10:05 by zuknapek          #+#    #+#             */
/*   Updated: 2026/03/08 15:10:05 by zuknapek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	
	//testing all levels:
	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	
	//invalid level
	harl.complain("asdf");
	
	return 0;
}
