FROM node:10
WORKDIR /usr/src
COPY package.json yarn.lock ./
RUN yarn
COPY . .
RUN npm run build
RUN npm run bundle
EXPOSE 3000
CMD [ "npm", "start" ]
