#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#pragma once

#include "lasote/httpserver/http_middleware.h"
#include "led.h"

namespace httpserver {

	class MyHttpMiddleware : public HttpMiddleware {
		public:
			MyHttpMiddleware() : HttpMiddleware(NULL){}
			MyHttpMiddleware(HttpMiddleware* other_middleware) : HttpMiddleware(other_middleware){

			}
			virtual ~MyHttpMiddleware();
			virtual void call(Request&, Response&);
		private:
			Led myLed;
	};

} /* namespace httpserver */

#ifdef __cplusplus
}
#endif

#endif /* WEB_SERVER_H */