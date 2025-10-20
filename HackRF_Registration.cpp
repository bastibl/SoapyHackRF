/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Wei Jiang
 * Copyright (c) 2015-2017 Josh Blum
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "SoapyHackRF.hpp"
#include <SoapySDR/Registry.hpp>

static std::map<std::string, SoapySDR::Kwargs> _cachedResults;

static std::vector<SoapySDR::Kwargs> find_HackRF(const SoapySDR::Kwargs &args)
{
	SoapyHackRFSession Sess;

	std::vector<SoapySDR::Kwargs> results;

	SoapySDR::Kwargs devInfo;
	devInfo["label"] = "HackRF";
	devInfo["product"] = "HackRF";
	devInfo["serial"] = "00000001";
	devInfo["fd"] = args.at("fd");

	results.push_back(devInfo);

	return results;
}

static SoapySDR::Device *make_HackRF(const SoapySDR::Kwargs &args)
{
    return new SoapyHackRF(args);
}

static SoapySDR::Registry register_hackrf("hackrf", &find_HackRF, &make_HackRF, SOAPY_SDR_ABI_VERSION);
