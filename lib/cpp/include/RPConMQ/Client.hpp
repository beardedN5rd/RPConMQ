/*
 *
 * Published under Apache License, Version 2.0 (the
 * "License"); See LICENSE file or obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */
#pragma once
#include <RPConMQ/essentials.hpp>

namespace RPConMQ {

class IClient;
using Client = std::shared_ptr<IClient>;

class IClient
{
private:
	static std::string correlation_id ()
	{
		return "unique";
	}
protected:
	IClient ();
public:
	virtual ~IClient ();
	virtual Response request (const Request& request) = 0;

	static Client create
	(	const std::string& init_data,
		const std::string& service_queue,
		const CorrelationCallBack& correlation_callback =
			std::bind(IClient::correlation_id));
};

}
