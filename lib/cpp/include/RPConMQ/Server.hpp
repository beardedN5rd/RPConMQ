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

class IServer;
using Server = std::shared_ptr<IServer>;

class IServer
{
public:
	virtual ~IServer();
	virtual void run() = 0;

	static Server create
	(	const std::string& init_data,
		const std::string& service_queue,
		const CallBack&	service_callback);
};

}
